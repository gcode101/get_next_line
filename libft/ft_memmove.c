/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 16:02:22 by gcortina          #+#    #+#             */
/*   Updated: 2016/09/23 16:02:24 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*p_dst;
	char const	*p_src;

	p_dst = (char*)dst;
	p_src = (char const*)src;
	if (p_dst == p_src)
		return (dst);
	if (p_src < p_dst)
	{
		p_src = p_src + len - 1;
		p_dst = p_dst + len - 1;
		while (len--)
			*p_dst-- = *p_src--;
	}
	else
	{
		while (len--)
			*p_dst++ = *p_src++;
	}
	return (dst);
}
