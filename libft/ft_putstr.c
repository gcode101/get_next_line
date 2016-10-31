/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 09:54:56 by gcortina          #+#    #+#             */
/*   Updated: 2016/09/26 12:29:01 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *str)
{
	int i;

	i = 0;
	if (str == NULL)
	{
		ft_putendl("(null)");
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
