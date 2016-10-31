/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 15:44:37 by gcortina          #+#    #+#             */
/*   Updated: 2016/08/26 22:57:01 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_infix(t_btree *root, void *data_ref,
								int (*applyf)(void *, void *))
{
	int		re_val;
	void	*found_node;

	found_node = 0;
	if (root)
	{
		found_node = btree_search_infix(root->left, data_ref, applyf);
		re_val = applyf(root->item, data_ref);
		if (re_val == 0)
		{
			found_node = root;
			return (found_node);
		}
		if (found_node == 0)
			found_node = btree_search_infix(root->right, data_ref, applyf);
	}
	return (found_node);
}

void	*btree_search_item(t_btree *root, void *data_ref,
								int (*cmpf)(void *, void *))
{
	return (btree_search_infix(root, data_ref, cmpf));
}
