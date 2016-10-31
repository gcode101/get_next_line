/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 11:58:42 by gcortina          #+#    #+#             */
/*   Updated: 2016/09/26 11:58:45 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	if (s == NULL)
	{
		ft_putstr("(null)");
		ft_putchar('\n');
		return ;
	}
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
	ft_putchar('\n');
}
