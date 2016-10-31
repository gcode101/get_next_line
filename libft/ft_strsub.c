/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 12:30:59 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/01 12:31:01 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(res = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len > 0)
	{
		res[i++] = s[start++];
		len--;
	}
	res[i] = '\0';
	return (res);
}
