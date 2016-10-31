/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 20:29:49 by gcortina          #+#    #+#             */
/*   Updated: 2016/08/16 20:29:51 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (n == 0)
		return (0);
	if (s2[0] == '\0')
		return ((unsigned char)s1[0] - (unsigned char)s2[0]);
	while ((int)n > 0 && s1[i] != '\0')
	{
		if (s2[j] > s1[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
		if (s1[i] > s2[j])
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
		i++;
		j++;
		n--;
	}
	if (s2[j] != '\0' && n != 0)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[j]);
	}
	return (0);
}
