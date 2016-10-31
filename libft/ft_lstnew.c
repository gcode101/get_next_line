/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:51:14 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/10 13:11:49 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;
	void	*new_cont;

	if (!(new_cont = ft_memalloc(content_size + 1)))
		return (NULL);
	temp = (t_list*)malloc(sizeof(t_list));
	if (temp)
	{
		temp->next = NULL;
		if (content == NULL)
		{
			temp->content = NULL;
			temp->content_size = 0;
		}
		else
		{
			ft_memcpy(new_cont, content, content_size);
			temp->content = new_cont;
			temp->content_size = content_size;
		}
	}
	return (temp);
}
