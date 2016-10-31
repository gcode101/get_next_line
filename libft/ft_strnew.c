/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 10:44:17 by gcortina          #+#    #+#             */
/*   Updated: 2016/09/26 10:44:19 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strnew(size_t size)
{
	unsigned char	*result;

	if (!(result = malloc(sizeof(char) * (size) + 1)))
		return (NULL);
	return (ft_memset(result, '\0', size + 1));
}
