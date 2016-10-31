/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 11:06:06 by gcortina          #+#    #+#             */
/*   Updated: 2016/09/25 11:06:08 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
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
	while (str[a] != '\0' || len-- == 0)
	{
		b = a;
		c = 0;
		while (str[b] == to_find[c] && b < (int)len)
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
