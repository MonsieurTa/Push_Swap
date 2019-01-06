/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 01:26:07 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 07:18:35 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/includes/ft_printf.h"
#include "link_list.h"
#include "operations.h"
#include "push_swap.h"
#include "read.h"
#include "tab_sort.h"
#include "sort.h"

void	two_rot(t_stacks *stacks)
{
	t_node	*node_a;
	t_node	*node_b;
	int		i;
	int		j;

	node_b = stacks->b.head;
	i = -1;
	while (++i < stacks->b.len)
	{
		j = -1;
		node_a = stacks->a.head;
		while (++j < stacks->a.len)
		{
			if (fit_in_a(node_b->value, node_a) == 1)
				get_opti_rot(stacks, "single", i, j);
			node_a = node_a->next;
		}
		node_b = node_b->next;
	}
}

void	stacks_rot(t_stacks *stacks)
{
	*(&stacks->rrr_rot) = stacks->a.len;
	*(&stacks->rb_rot) = stacks->b.len;
	*(&stacks->a_rot) = stacks->a.len;
	*(&stacks->b_rot) = stacks->b.len;
	double_rot(stacks);
	two_rot(stacks);
	if (ft_abs(stacks->rrr_rot) + ft_abs(stacks->rb_rot) < ft_abs(
				stacks->a_rot) + ft_abs(stacks->b_rot))
	{
		move_stacks(&stacks->a, &stacks->b, stacks->a_rot, 'x');
		move_stacks(&stacks->a, &stacks->b, stacks->b_rot, 'b');
	}
	else
	{
		move_stacks(&stacks->a, &stacks->b, stacks->a_rot, 'a');
		move_stacks(&stacks->a, &stacks->b, stacks->b_rot, 'b');
	}
}

int		get_min(t_lst *a)
{
	t_node	*node;
	int		min;
	int		i;

	node = a->head;
	min = node->value;
	i = -1;
	while (++i < a->len)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	return (min);
}

int		get_min_rot(t_lst *a, int min)
{
	t_node	*node;
	int		i;

	node = a->head;
	i = 0;
	while (i < a->len)
	{
		if (node->value == min)
			break ;
		node = node->next;
		i++;
	}
	return (opti_rot(a, i));
}

void	insertion_sort(t_stacks *stacks)
{
	while (stacks->a.len > 3)
		push_lst(&stacks->a, &stacks->b, "a to b", 'b');
	small_sort(&stacks->a, 'a');
	while (stacks->b.len > 0)
	{
		stacks_rot(stacks);
		push_lst(&stacks->a, &stacks->b, "b to a", 'a');
	}
	move_stacks(&stacks->a, &stacks->b, get_min_rot(&stacks->a,
				get_min(&stacks->a)), 'a');
}
