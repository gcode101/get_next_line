/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:33:32 by gcortina          #+#    #+#             */
/*   Updated: 2016/09/22 21:33:34 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
						int c, size_t n)
{
	char		*p_dst;
	char const	*p_src;

	p_dst = (char*)dst;
	p_src = (char const*)src;
	while (n > 0)
	{
		*p_dst = *p_src;
		if (*p_src == c)
			return (++p_dst);
		p_dst++;
		p_src++;
		n--;
	}
	return (NULL);
}
