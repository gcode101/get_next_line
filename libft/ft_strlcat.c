/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 10:32:46 by gcortina          #+#    #+#             */
/*   Updated: 2016/09/24 10:32:53 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	len;
	size_t	needed;
	char	*end;

	src_len = ft_strlen(src);
	end = (char*)ft_memchr(dst, '\0', size);
	if (!end)
		return (size + src_len);
	dst_len = end - dst;
	len = dst_len + src_len + 1;
	needed = dst_len + src_len + 1;
	if (len >= size)
		len = size - 1;
	ft_memcpy(dst + dst_len, src, len - dst_len);
	dst[len] = '\0';
	return (needed - 1);
}
