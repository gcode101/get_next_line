/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:33:42 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/01 14:33:47 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		no_space(char const *str, int end)
{
	if ((str[0] != ' ' && str[0] != '\n' && str[0] != '\t') &&
			(str[end] != ' ' && str[end] != '\n' && str[end] != '\t'))
		return (1);
	else
		return (0);
}

static int		full_blank(char const *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static char		*new_str(char const *str, int size)
{
	char *res;

	if (!(res = ft_strnew(size)))
		return (NULL);
	else
		return (ft_strcpy(res, str));
}

char			*ft_strtrim(char const *s)
{
	char	*res;
	int		end;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (full_blank(s))
		return (res = ft_strnew(0));
	end = ft_strlen(s) - 1;
	if (no_space(s, end))
		return (new_str(s, end + 1));
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (!(res = malloc(sizeof(char) * (end - i + 1) + 1)))
		return (NULL);
	while (s[i] && i <= end)
		res[j++] = s[i++];
	res[j] = '\0';
	return (res);
}
