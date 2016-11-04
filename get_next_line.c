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
		{
			if (str[i])
				return (1);
		}
	}
	return (0);
}

static char	*check_buf(char *line, char *buf, char *piece_ofstr)
{
	int		i;
	char	*substr;

	i = 0;
	// printf("%s\n", "Inside check_buf");
	// printf("buf:\n%s\n", buf);
	if (ft_strlen(buf))
	{
		// printf("piece_ofstr: %s\n", piece_ofstr);
		while (piece_ofstr && piece_ofstr[i] && piece_ofstr[i] != '\n')
			i++;
		if (ft_strlen(line) == 0)
			line = ft_strjoin(line, ft_strsub(piece_ofstr, 0, i));
		// printf("line: %s\n", line);
		i = 0;
		while (buf[i] && buf[i] != '\n')
			i++;
		substr = ft_strsub(buf, 0, i);
		// printf("substr: %s\n", substr);
		line = ft_strjoin(line, substr);
		// printf("line: %s\n", line);
	}
	else
	{
		while (piece_ofstr[i] && piece_ofstr[i] != '\n')
			i++;
		substr = ft_strsub(piece_ofstr, 0, i);
		// printf("else substr: %s\n", substr);
		line = ft_strjoin(line, substr);
		// printf("else line: %s\n", line);
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
		while (buf[i] && buf[i] != '\n')
			i++;
		j = i + 1;
		while (buf[j++])
			len++;
		if (buf[i])
			piece_ofstr = ft_strsub(buf, i + 1, len);
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

	if (!(*line = ft_strnew(1)))
		return (0);
	if (fd >= 0)
	{
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			buf[ret] = '\0';
			if (has_newline(buf))
			{
				// printf("%s\n", "newline");
				*line = check_buf(*line, buf, piece_ofstr);
				piece_ofstr = missing_str(buf, piece_ofstr);
				return (1);
			}
			else
			{
				if (has_newline(piece_ofstr))
				{	
					i = 0;
					// printf("%s\n", "piece_ofstr has newline");
					while (piece_ofstr && piece_ofstr[i] != '\n')
						i++;
					*line = ft_strjoin(*line, ft_strsub(piece_ofstr, 0, i));
					// printf("line: %s\n", *line);
					// piece_ofstr = ft_strjoin(piece_ofstr, buf);
					piece_ofstr = missing_str(buf, piece_ofstr);
					// printf("piece_ofstr: %s\n", piece_ofstr);
					return (1);
				}
				// printf("%s\n", "no newline");
				*line = check_buf(*line, buf, piece_ofstr);
				piece_ofstr = missing_str(buf, piece_ofstr);
			}
		}		
		if (piece_ofstr && ft_strlen(piece_ofstr))
		{
			*line = check_buf(*line, buf, piece_ofstr);
			piece_ofstr = missing_str(buf, piece_ofstr);
			// printf("%s\n", "read is done");
			// printf("line: %s\n", *line);
			// printf("piece_ofstr: %s\n", piece_ofstr);
			return (1);
		}
		else if (*line && ft_strlen(*line))
			return (1);
		else
		{
			// printf("%s\n", "now it returns 0");
			return (0);
		}
	}
	else
		return (-1);
}
