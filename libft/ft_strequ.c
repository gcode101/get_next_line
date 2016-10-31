/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 11:36:17 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/01 11:36:20 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		equal;

	equal = 0;
	if (s1 == NULL || s2 == NULL)
		return (equal);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (equal);
	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return (equal = 1);
	while (*s1)
	{
		if (*s1 != *s2)
			return (equal = 0);
		else
			equal = 1;
		s1++;
		s2++;
	}
	return (equal);
}
