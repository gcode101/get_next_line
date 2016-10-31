/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:53:48 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/01 15:53:54 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(const char *str, char c)
{
	int		in_word;
	int		count;

	in_word = 0;
	count = 0;
	while (*str)
	{
		if (!in_word && *str != c)
		{
			in_word = 1;
			count++;
		}
		else if (in_word && *str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static int		ft_word_length(const char *str, int i, char c)
{
	int		total;

	total = 0;
	while (str[i] != c && str[i])
	{
		total++;
		i++;
	}
	return (total);
}

static char		**split_helper(char const *s, char **words, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while ((s[i] == c) && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			if (!(words[j] = malloc(sizeof(char) *
					(ft_word_length(s, i, c) + 1))))
				return (NULL);
			while (s[i] != c && s[i])
				words[j][k++] = s[i++];
			words[j++][k] = '\0';
		}
	}
	words[j] = 0;
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;

	if (s == NULL)
		return (NULL);
	if (!(words = malloc(sizeof(char*) * (ft_word_count(s, c) + 1))))
		return (NULL);
	return (split_helper(s, words, c));
}
