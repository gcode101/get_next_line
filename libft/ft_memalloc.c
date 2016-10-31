/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 09:51:16 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/21 17:23:21 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;

	if (!size)
		return (NULL);
	if (!(res = malloc(size)))
		return (NULL);
	ft_bzero(res, size);
	return (res);
}
