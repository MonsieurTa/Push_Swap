/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:28:31 by wta               #+#    #+#             */
/*   Updated: 2018/12/31 11:07:42 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "link_list.h"
#include "operations.h"

void	swap(t_lst *lst)
{
	t_node	*node;
	int		tmp;

	if (lst->len >= 2)
	{
		node = lst->head;
		tmp = node->value;
		node->value = node->next->value;
		node->next->value = tmp;
	}
}

void	push_lst(t_lst *l1, t_lst *l2)
{
	t_node	*node;
	if (l2 && l2->len > 0)
	{
		if ((node = pop_front(l2)) != NULL)
		{
			pushfront(l1, node);
		}
	}
}

void	rotate(t_lst *lst)
{
	if (lst && lst->len >= 2)
	{
		lst->head = lst->head->next;
		lst->tail = lst->tail->next;
	}
}

void	reverse_rotate(t_lst *lst)
{
	if (lst && lst->len >= 2)
	{
		lst->head = lst->head->prev;
		lst->tail = lst->tail->prev;
	}
}
