/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 12:15:57 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/01 12:16:00 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		equal;

	equal = 0;
	if (s1 == NULL || s2 == NULL)
		return (equal);
	if ((ft_strlen(s1) == 0 && ft_strlen(s2) == 0) || n == 0)
		return (equal = 1);
	while (*s1 && *s2 && n > 0)
	{
		if (*s1 != *s2)
			return (equal = 0);
		else
			equal = 1;
		s1++;
		s2++;
		n--;
	}
	return (equal);
}
