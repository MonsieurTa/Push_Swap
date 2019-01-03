/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:28:31 by wta               #+#    #+#             */
/*   Updated: 2019/01/03 02:36:46 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
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
		ft_printf("sa\n");
	}
}

void	push_lst(t_lst *a, t_lst *b, char *str)
{
	t_node	*node;

	if (ft_strequ(str, "a to b") == 1)
	{
		if (a && a->len > 0)
		{
			if ((node = pop_front(a)) != NULL)
			{
				pushfront(b, node);
				ft_printf("pb\n");
			}
		}
	}
	else if (ft_strequ(str, "b to a") == 1)
	{
		if (b && b->len > 0)
		{
			if ((node = pop_front(b)) != NULL)
			{
				pushfront(a, node);
				ft_printf("pa\n");
			}
		}
	}
}

void	rotate(t_lst *lst)
{
	if (lst && lst->len >= 2)
	{
		lst->head = lst->head->next;
		lst->tail = lst->tail->next;
		ft_printf("ra\n");
	}
}

void	reverse_rotate(t_lst *lst)
{
	if (lst && lst->len >= 2)
	{
		lst->head = lst->head->prev;
		lst->tail = lst->tail->prev;
		ft_printf("rra\n");
	}
}
