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

static char	*ft_concat(char *s1, char *s2)
{
	char	*result;

	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result)
	{
		ft_strcpy(result, s1);
		ft_strcat(result, s2);
	}
	return (result);
}

int			get_next_line(const int fd, char **line)
{
	static int	i;
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*str;
	int			a_line;
	static int	j;
	int			x;

	i = 0;
	j = 0;
	x = 0;
	if (fd >= 0)
	{
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			buf[ret] = '\0';
			str = ft_concat(str, buf);
		}
		a_line = j;
		while (str[a_line] != '\n')
			a_line++;
		line = (char**)malloc(sizeof(char*) * (i) + 2);
		line[i] = malloc(sizeof(char) * a_line + 1);
		j = 0;
		while (str[j] && str[j] != '\n')
		{
			line[i][j] = str[j];
			j++;
		}
		line[i][j] = '\0';
		i++;
		printf("line[%d]: %s\n", i - 1, line[i - 1]);
		if (str[j])
			return (1);
		else
			return (0);
	}
	else
		return (-1);
}
