/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 21:02:16 by gcortina          #+#    #+#             */
/*   Updated: 2016/09/01 21:16:48 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	c = 0;
	if (ft_strlen(to_find) == 0)
		return ((char*)str);
	if (ft_strlen(str) == 0)
		return (NULL);
	while (str[a] != '\0')
	{
		b = a;
		c = 0;
		while (str[b] == to_find[c])
		{
			b++;
			c++;
			if (to_find[c] == '\0')
				return ((char*)&str[a]);
		}
		a++;
	}
	return (NULL);
}
