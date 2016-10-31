/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:39:56 by gcortina          #+#    #+#             */
/*   Updated: 2016/09/22 20:39:58 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p_dst;
	char const	*p_src;

	p_dst = (char*)dst;
	p_src = (char const*)src;
	while (n > 0)
	{
		*p_dst = *p_src;
		p_dst++;
		p_src++;
		n--;
	}
	return (dst);
}
