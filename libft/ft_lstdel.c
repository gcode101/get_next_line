/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 12:45:43 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/05 12:45:45 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *temp;

	temp = *alst;
	if (temp && del)
	{
		while (temp)
		{
			del(temp->content, temp->content_size);
			free(temp);
			temp = temp->next;
		}
		*alst = NULL;
	}
}
