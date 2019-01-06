/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:49:22 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 03:09:12 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/includes/ft_printf.h"
#include "link_list.h"
#include "operations.h"
#include "push_swap.h"

void	get_double_rot(t_stacks *stacks)
{
	t_node	*node_a;
	t_node	*node_b;
	t_node	*tmp_b;
	int		i;
	int		j;

	node_a = stacks->a.head;
	node_b = stacks->b.head;
	i = -1;
	while (++i < stacks->a.len)
	{
		tmp_b = node_b;
		j = -1;
		while (++j < stacks->b.len)
		{
			if (fit_in(node_a->value, tmp_b) == 1)
				set_opti_rot(stacks, "double", i, j);
			tmp_b = tmp_b->next;
		}
		node_a = node_a->next;
		node_b = node_b->next;
	}
}

void	get_two_rot(t_stacks *stacks)
{
	t_node	*node_a;
	t_node	*node_b;
	int		i;
	int		j;

	node_a = stacks->a.head;
	i = -1;
	while (++i < stacks->a.len)
	{
		j = -1;
		node_b = stacks->b.head;
		while (++j < stacks->b.len)
		{
			if (fit_in(node_a->value, node_b) == 1)
				set_opti_rot(stacks, "single", i, j);
			node_b = node_b->next;
		}
		node_a = node_a->next;
	}
}

void	two_stack_rot(t_stacks *stacks)
{
	*(&stacks->rrr_rot) = stacks->a.len;
	*(&stacks->rb_rot) = stacks->b.len;
	*(&stacks->a_rot) = stacks->a.len;
	*(&stacks->b_rot) = stacks->b.len;
	get_double_rot(stacks);
	get_two_rot(stacks);
	if (ft_abs(stacks->rrr_rot) + ft_abs(stacks->rb_rot) < ft_abs(
				stacks->a_rot) + ft_abs(stacks->b_rot))
	{
		move_stacks(&stacks->a, &stacks->b, stacks->rrr_rot, 'x');
		move_stacks(&stacks->a, &stacks->b, stacks->rb_rot, 'b');
	}
	else
	{
		move_stacks(&stacks->a, &stacks->b, stacks->a_rot, 'a');
		move_stacks(&stacks->a, &stacks->b, stacks->b_rot, 'b');
	}
}

void	small_sort(t_lst *lst, char c)
{
	if (c == 'b')
	{
		while (is_sort_from_h(lst) == 0)
		{
			if (lst->head->next->value > lst->head->value)
				swap(lst, 'b');
			else if (lst->tail->value > lst->head->value)
				rev_rot(lst, 'b');
			else if (lst->head->next->value < lst->tail->value)
				rev_rot(lst, 'b');
		}
	}
	else
	{
		while (is_sort(lst) == 0)
		{
			if (lst->head->next->value < lst->head->value)
				swap(lst, 'a');
			else if (lst->tail->value < lst->head->value)
				rev_rot(lst, 'a');
			else if (lst->head->next->value > lst->tail->value)
				rev_rot(lst, 'a');
		}
	}
}

void	selection_sort(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i++ < 3)
		push_lst(&stacks->a, &stacks->b, "a to b", 'b');
	small_sort(&stacks->b, 'b');
	while (stacks->a.len > 0)
	{
		two_stack_rot(stacks);
		push_lst(&stacks->a, &stacks->b, "a to b", 'b');
	}
	move_stacks(&stacks->a, &stacks->b, best_b_rot(&stacks->b,
		get_max(&stacks->b)), 'b');
	while (stacks->b.len > 0)
		push_lst(&stacks->a, &stacks->b, "b to a", 'a');
}
