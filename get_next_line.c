/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 11:28:56 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/29 11:28:58 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	has_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i++] == '\n')
				return (1);
	}
	return (0);
}

static char	*check_buf(char *line, char *buf, char *piece_ofstr)
{
	int		i;
	char	*substr;

	i = 0;
	printf("%s\n", "Inside check_buf");
	printf("buf:\n%s\n", buf);
	if (ft_strlen(buf))
	{
		printf("piece_ofstr: %s\n", piece_ofstr);
		while (piece_ofstr && piece_ofstr[i] && piece_ofstr[i] != '\n')
			i++;
		if (ft_strlen(line) == 0)
			line = ft_strjoin(line, ft_strsub(piece_ofstr, 0, i));
		printf("line: %s\n", line);
		i = 0;
		while (buf[i] && buf[i] != '\n')
			i++;
		substr = ft_strsub(buf, 0, i);
		printf("substr: %s\n", substr);
		line = ft_strjoin(line, substr);
		printf("line: %s\n", line);
	}
	else
	{
		while (piece_ofstr[i] && piece_ofstr[i] != '\n')
			i++;
		substr = ft_strsub(piece_ofstr, 0, i);
		printf("else substr: %s\n", substr);
		line = ft_strjoin(line, substr);
		printf("else line: %s\n", line);
	}
	return (line);
}

static char	*missing_str(char *buf, char *piece_ofstr)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	if (ft_strlen(buf) && !(has_newline(piece_ofstr)))
	{
		printf("%s\n", "inside missing_str");
		while (buf[i] && buf[i] != '\n')
			i++;
		j = i + 1;
		while (buf[j++])
			len++;
		if (buf[i])
		{
			free(piece_ofstr);
			piece_ofstr = ft_strsub(buf, i + 1, len);
		}
		printf("piece_ofstr: %s\n", piece_ofstr);
	}
	else
	{
		if (ft_strlen(buf))
			piece_ofstr = ft_strjoin(piece_ofstr, buf);
		while (piece_ofstr[i] && piece_ofstr[i] != '\n')
			i++;
		piece_ofstr = &piece_ofstr[i + 1];
		// printf("else piece_ofstr: %s\n", piece_ofstr);
	}
	return (piece_ofstr);
}

int			get_next_line(const int fd, char **line)
{
	int			i;
	int			ret;
	char		buf[BUFF_SIZE];
	static char	*piece_ofstr;

	if (!line || !*line || !(*line = ft_strnew(1)))
		return (-1);
	if (!piece_ofstr)
	{
		printf("piece_ofstr before: %s\n", piece_ofstr);
		printf("%s\n", "piece_ofstr gets initialized");
		if (!(piece_ofstr = ft_strnew(1)))
			return (-1);
		printf("piece_ofstr after: %s\n", piece_ofstr);
	}
	if (fd >= 0)
	{
		printf("%s\n", "right before read");
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			printf("%s\n", "inside read");
			buf[ret] = '\0';
			printf("buf: %s\n", buf);
			if (has_newline(piece_ofstr))
			{	
				i = 0;
				printf("%s\n", "piece_ofstr has newline");
				while (piece_ofstr && piece_ofstr[i] != '\n')
					i++;
				*line = ft_strjoin(*line, ft_strsub(piece_ofstr, 0, i));
				printf("line: %s\n", *line);
				piece_ofstr = missing_str(buf, piece_ofstr);
				printf("piece_ofstr: %s\n", piece_ofstr);
				return (1);
			}			
			else if (has_newline(buf))
			{
				printf("%s\n", "buf has newline");
				*line = check_buf(*line, buf, piece_ofstr);
				piece_ofstr = missing_str(buf, piece_ofstr);
				return (1);
			}
			else
			{
				printf("%s\n", "no newline in buf");
				*line = check_buf(*line, buf, piece_ofstr);
				piece_ofstr = missing_str(buf, piece_ofstr);
			}
		}
		printf("%s\n", "read is done");
		ft_memset(buf, '\0', ft_strlen(buf));
		if (piece_ofstr && ft_strlen(piece_ofstr))
		{
			*line = check_buf(*line, buf, piece_ofstr);
			piece_ofstr = missing_str(buf, piece_ofstr);
			printf("line: %s\n", *line);
			printf("piece_ofstr: %s\n", piece_ofstr);
			return (1);
		}
		else if (*line && ft_strlen(*line))
			return (1);
		else
		{
			printf("%s\n", "now it returns 0");
			return (0);
		}
	}
	else
		return (-1);
}
