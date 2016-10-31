/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 16:32:17 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/17 12:34:57 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*min_val(void)
{
	char	*results;

	if (!(results = ft_strnew(11)))
		return (NULL);
	return (ft_strcpy(results, "-2147483648"));
}

static char	*fill_results(char *results, int digits, int neg, int nb_copy)
{
	results[digits + neg] = '\0';
	while (digits > 0)
	{
		if (neg)
			results[digits] = (nb_copy % 10) + '0';
		else
			results[digits - 1] = (nb_copy % 10) + '0';
		nb_copy /= 10;
		digits--;
	}
	if (neg)
		results[0] = '-';
	return (results);
}

static int	digit_num(int nb)
{
	int		digits;

	digits = 1;
	while (nb != 0)
	{
		digits++;
		nb /= 10;
	}
	return (digits);
}

char		*ft_itoa(int nb)
{
	int		digits;
	int		nb_copy;
	char	*results;
	int		neg;

	nb_copy = nb;
	neg = 0;
	if (nb == -2147483648)
		return (min_val());
	digits = digit_num(nb_copy);
	if (digits > 1)
		digits--;
	nb_copy = nb;
	if (nb < 0)
	{
		neg = 1;
		nb_copy *= -1;
	}
	if (!(results = malloc(sizeof(char) * digits + 1 + neg)))
		return (NULL);
	return (fill_results(results, digits, neg, nb_copy));
}
