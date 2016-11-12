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

static void	check_buf(char **line, char *buf, char **piece_ofstr)
{
	char	*temp;

	//printf("%s\n", "Inside check_buf");
	if (buf && ft_strlen(buf))
	{
		//printf("%s\n", "buf has something");
		//printf("piece_ofstr: %s\n", *piece_ofstr);
		if (*piece_ofstr && (temp = ft_strchr(*piece_ofstr, '\n')) && ft_strlen(*line) == 0)
		{
			*temp = '\0';
			//printf("piece_ofstr has newline and line is empty piece_ofstr: %s\n", *piece_ofstr);
			*line = ft_strjoin(*line, *piece_ofstr);
			//printf("line gets join with piece_ofstr line: %s\n", *line);
			*piece_ofstr = ft_strdup(temp + 1);
			//printf("piece_ofstr gets the rest piece_ofstr: %s\n", *piece_ofstr);
			temp = NULL;
			if (!ft_strlen(*piece_ofstr))
			{
				ft_memdel((void**)piece_ofstr);
				//printf("piece_ofstr is empty so it gets free here piece_ofstr: %s\n", *piece_ofstr);
			}
		}
		else if (ft_strlen(*line) == 0)
		{
			*line = ft_strjoin(*line, *piece_ofstr);
			//printf("piece_ofstr doesnt have a newline so it joins line: %s\n", *line);
			ft_memdel((void**)piece_ofstr);
			//printf("piece_ofstr gets free here piece_ofstr: %s\n", *piece_ofstr);			
		}
		if ((temp = ft_strchr(buf, '\n')))
		{
			//printf("buf has a newline buf:\n%s\n", buf);
			*temp = '\0';
			*line = ft_strjoin(*line, buf);
			//printf("buf joins line: %s\n", *line);
			*piece_ofstr = ft_strdup(temp + 1);
			//printf("piece_ofstr gets the rest of the buf piece_ofstr: %s\n", *piece_ofstr);
			temp = NULL;
			if (!ft_strlen(*piece_ofstr))
			{
				ft_memdel((void**)piece_ofstr);
				//printf("piece_ofstr gets free here piece_ofstr: %s\n", *piece_ofstr);
			}
		}
		else
		{
			*line = ft_strjoin(*line, buf);
			//printf("buf doesnt have a newline so joins line: %s\n", *line);
		}
	}
	else
	{
		//printf("buf is empty buf: %s\n", buf);
		if ((temp = ft_strchr(*piece_ofstr, '\n')))
		{
			//printf("piece_ofstr has newline piece_ofstr: %s\n", *piece_ofstr);
			*temp = '\0';
			*line = ft_strjoin(*line, *piece_ofstr);
			//printf("piece_ofstr joins line: %s\n", *line);
			*piece_ofstr = ft_strdup(temp + 1);
			//printf("piece_ofstr gets the rest piece_ofstr: %s\n", *piece_ofstr);
			temp = NULL;
			if (!ft_strlen(*piece_ofstr))
			{
				ft_memdel((void**)piece_ofstr);
				//printf("piece_ofstr gets free here piece_ofstr: %s\n", *piece_ofstr);
			}
		}
		else
		{
			*line = ft_strjoin(*line, *piece_ofstr);
			//printf("piece_ofstr does not have newline piece_ofstr: %s\n", *piece_ofstr);
			//printf("piece_ofstr joins line: %s\n", *line);
			ft_memdel((void**)piece_ofstr);
			//printf("piece_ofstr gets free here piece_ofstr: %s\n", *piece_ofstr);			
		}		
	}
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		*buf;
	char		*temp;
	static char	*piece_ofstr;

	if (!line || !(*line = ft_strnew(1)))
		return (-1);
	if (!piece_ofstr)
	{
		//printf("piece_ofstr before: %s\n", piece_ofstr);
		//printf("%s\n", "piece_ofstr gets initialized");
		if (!(piece_ofstr = ft_strnew(1)))
			return (-1);
		//printf("piece_ofstr after: %s\n", piece_ofstr);
	}
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (fd >= 0)
	{
		//printf("%s\n", "right before read");
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			if (!ft_strlen(buf))
				return -1;
			//printf("%s\n", "inside read");
			//printf("ret: %d\n", ret);
			buf[ret] = '\0';
			//printf("buf: %s\n", buf);
			if (piece_ofstr && (temp = ft_strchr(piece_ofstr, '\n')))
			{
				*temp = '\0';	
				//printf("%s\n", "piece_ofstr has newline");
				*line = ft_strjoin(*line, piece_ofstr);
				//printf("line: %s\n", *line);
				piece_ofstr = ft_strdup(temp + 1);
				piece_ofstr = ft_strjoin(piece_ofstr, buf);
				//printf("piece_ofstr: %s\n", piece_ofstr);
				temp = NULL;
				ft_memdel((void**)&buf);
				//printf("buf gets free here buf: %s\n", buf);
				return (1);
			}			
			else if (ft_strchr(buf, '\n'))
			{
				//printf("%s\n", "buf has newline");
				check_buf(line, buf, &piece_ofstr);
				ft_memdel((void**)&buf);
				//printf("buf gets free here buf: %s\n", buf);
				return (1);
			}
			else
			{
				//printf("%s\n", "no newline in buf");
				check_buf(line, buf, &piece_ofstr);
			}
		}
		//printf("%s\n", "read is done");
		ft_memdel((void**)&buf);
		//printf("buf gets free here buf: %s\n", buf);
		if (piece_ofstr && ft_strlen(piece_ofstr))
		{
			check_buf(line, buf, &piece_ofstr);
			//printf("line: %s\n", *line);
			//printf("piece_ofstr: %s\n", piece_ofstr);
			return (1);
		}
		else if (*line && ft_strlen(*line))
			return (1);
		else
		{
			//printf("%s\n", "now it returns 0");
			return (0);
		}
	}
	else
		return (-1);
}
