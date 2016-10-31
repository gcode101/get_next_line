/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 21:31:47 by gcortina          #+#    #+#             */
/*   Updated: 2016/09/29 21:31:48 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*res;
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char*)s;
	if (str == NULL || f == NULL)
		return (NULL);
	if (!(res = malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		res[i] = f(str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
