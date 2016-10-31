/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 19:23:27 by gcortina          #+#    #+#             */
/*   Updated: 2016/09/23 19:23:29 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		val;
	const unsigned char	*str;

	str = s;
	val = (char)c;
	while (n)
	{
		if (val == *str)
			return ((void*)str);
		str++;
		n--;
	}
	return (NULL);
}
