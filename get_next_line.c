/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 11:28:56 by gcortina          #+#    #+#             */
/*   Updated: 2016/11/14 13:30:38 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	init_or_join(char **line, char **buf, char **piece_ofstr)
{
	if (buf)
	{
		if (!line || !(*line = ft_strnew(1)))
			return (-1);
		if (!*piece_ofstr && !(*piece_ofstr = ft_strnew(1)))
			return (-1);
		if (!(*buf = ft_strnew(BUFF_SIZE)))
			return (-1);
	}
	else
	{
		*line = ft_strjoin(*line, *piece_ofstr);
		ft_memdel((void**)piece_ofstr);
	}
	return (0);
}

static void	add_toline(char **line, char *buf, char **piece_ofstr, char *temp)
{
	*temp = '\0';
	if (buf)
		*line = ft_strjoin(*line, buf);
	else
		*line = ft_strjoin(*line, *piece_ofstr);
	*piece_ofstr = ft_strdup(temp + 1);
	temp = NULL;
	if (!ft_strlen(*piece_ofstr))
		ft_memdel((void**)piece_ofstr);
}

static void	check_buf(char **line, char *buf, char **piece_ofstr)
{
	char	*temp;

	if (buf && ft_strlen(buf))
	{
		if (*piece_ofstr && (temp = ft_strchr(*piece_ofstr, '\n'
			&& ft_strlen(*line) == 0)))
			add_toline(line, NULL, piece_ofstr, temp);
		else if (ft_strlen(*line) == 0)
			init_or_join(line, NULL, piece_ofstr);
		if ((temp = ft_strchr(buf, '\n')))
			add_toline(line, buf, piece_ofstr, temp);
		else
			*line = ft_strjoin(*line, buf);
	}
	else
	{
		if ((temp = ft_strchr(*piece_ofstr, '\n')))
			add_toline(line, NULL, piece_ofstr, temp);
		else
			init_or_join(line, NULL, piece_ofstr);
	}
}

static int	read_file(char *buf, char **line, char **piece_ofstr, int ret)
{
	char	*temp;

	if (!ft_strlen(buf))
		return (-1);
	buf[ret] = '\0';
	if (*piece_ofstr && (temp = ft_strchr(*piece_ofstr, '\n')))
	{
		add_toline(line, NULL, piece_ofstr, temp);
		if (!*piece_ofstr && !(*piece_ofstr = ft_strnew(1)))
			return (-1);
		*piece_ofstr = ft_strjoin(*piece_ofstr, buf);
		ft_memdel((void**)&buf);
		return (1);
	}
	else if (ft_strchr(buf, '\n'))
	{
		check_buf(line, buf, piece_ofstr);
		ft_memdel((void**)&buf);
		return (1);
	}
	else
		check_buf(line, buf, piece_ofstr);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	int			rd;
	char		*buf;
	static char	*piece_ofstr;

	if ((rd = init_or_join(line, &buf, &piece_ofstr)))
		return (rd);
	if (fd >= 0)
	{
		while ((ret = read(fd, buf, BUFF_SIZE)))
			if ((rd = read_file(buf, line, &piece_ofstr, ret)))
				return (rd);
		ft_memdel((void**)&buf);
		if (piece_ofstr && ft_strlen(piece_ofstr))
		{
			check_buf(line, buf, &piece_ofstr);
			return (1);
		}
		else if (*line && ft_strlen(*line))
			return (1);
		else
			return (0);
	}
	else
		return (-1);
}
