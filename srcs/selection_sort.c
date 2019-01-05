/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:49:22 by wta               #+#    #+#             */
/*   Updated: 2019/01/05 03:59:31 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/includes/ft_printf.h"
#include "link_list.h"
#include "operations.h"
#include "push_swap.h"

int		is_sort_from_h(t_lst *b)
{
	t_node	*node;
	int		i;

	node = b->head;
	if (node != NULL)
	{
		i = 0;
		while (i < b->len - 1)
		{
			if (node->value < node->next->value)
				return (0);
			node = node->next;
			i++;
		}
	}
	return (1);
}

int		get_max(t_lst *b)
{
	t_node	*node;
	int		value;

	node = b->head;
	value = node->value;
	while (value < node->prev->value)
	{
		node = node->prev;
		value = node->value;
	}
	return (value);
}

int		d_from_max(t_lst *b, int value)
{
	t_node	*node;
	int		max;
	int		i;

	node = b->head;
	max = get_max(b);
	while (node->value != max)
		node = node->prev;
	i = 0;
	while (i < b->len && value < node->value)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void	move_stacks(t_lst *a, t_lst *b, int len, char c)
{
	if (len > 0)
	{
		while (len-- > 0)
			rot((c == 'b') ? b : a, c);
	}
	else
	{
		while (len++ < 0)
			rev_rot((c == 'b') ? b : a, c);
	}
}

int	best_b_rot(t_lst *b, int value)
{
	int	opti;
	int	len;
	int	mid;

	len = d_from_max(b, value) - d_from_max(b, b->head->value);
	opti = (len < 0) ? b->len - ft_abs(len) : len - b->len;
	if (ft_abs(opti) <= b->len / 2)
		len = opti;
	return (len);
}

int	fit_in_b(int value_a, t_node *node_b)
{
	if (node_b->prev->value < node_b->value)
	{
		if (value_a > node_b->value
		|| value_a < node_b->prev->value)
			return (1);
	}
	else
	{
		if (value_a > node_b->value && value_a < node_b->prev->value)
			return (1);
	}
	return (0);
}

int	best_a_rot(t_lst *a, t_lst *b, int value)
{
	t_node	*node;
	int	len;
	int	mid;

	len = 0;
	node = a->head;
	mid = a->len / 2;
	while (len < a->len && fit_in_b(node->value, b->head) == 0)
	{
		node = node->next;
		len += 1;
	}
	if (len == a->len)
		return (b->len);
	if (len >= mid)
		len = len - a->len;
	return (len);
}

int		opti_rot(t_lst *stack, int rot)
{
	if (rot >= stack->len / 2)
		rot = rot - stack->len;
	return (rot);
}

void	get_two_rot(t_lst *a, t_lst *b, int *a_rot, int *b_rot)
{
	t_node	*node_a;
	t_node	*node_b;
	int		i;
	int		j;

	node_a = a->head;
	i = -1;
	while (++i < a->len)
	{
		j = -1;
		node_b = b->head;
		while (++j < b->len)
		{
			if (fit_in_b(node_a->value, node_b) == 1)
			{
				if (*a_rot == -1 && *b_rot == -1)
				{
					*a_rot = opti_rot(a, i);
					*b_rot = opti_rot(b, j);
				}
				else if (ft_abs(opti_rot(a, i)) + ft_abs(opti_rot(b, j)) < ft_abs(*a_rot) + ft_abs(*b_rot))
				{
					*a_rot = opti_rot(a, i);
					*b_rot = opti_rot(b, j);
				}
			}
			node_b = node_b->next;
		}
		node_a = node_a->next;
	}
	move_stacks(a, b, *a_rot, 'a');
	move_stacks(a, b, *b_rot, 'b');
}

void	two_stack_rot(t_lst *a, t_lst *b)
{
	int	a_rot;
	int	b_rot;

	a_rot = -1;
	b_rot = -1;
	get_two_rot(a, b, &a_rot, &b_rot);
}

void	one_stack_rot(t_lst *a, t_lst *b)
{
	int	dist_b;
	int	dist_a;

	dist_b = best_b_rot(b, a->head->value);
	dist_a = best_a_rot(a, b, b->head->value);
	if (dist_b < dist_a)
		move_stacks(a, b, dist_b, 'b');
	else
		move_stacks(a, b, dist_a, 'a');
}

void	insert(t_lst *a, t_lst *b)
{
	two_stack_rot(a, b);
//	one_stack_rot(a, b);
	push_lst(a, b, "a to b", 'b');
}

void	small_sort(t_lst *b)
{
	while (is_sort_from_h(b) == 0)
	{
		if (b->head->next->value > b->head->value)
			swap(b, 'b');
		else if (b->tail->value > b->head->value)
			rev_rot(b, 'b');
		else if (b->head->next->value < b->tail->value)
			rev_rot(b, 'b');
	}
}

void	selection_sort(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i++ < 3)
		push_lst(&stacks->a, &stacks->b, "a to b", 'b');
	small_sort(&stacks->b);
	while (stacks->a.len > 0)
		insert(&stacks->a, &stacks->b);
//	print_list(&stacks->a);
//	print_list(&stacks->b);
//	smallest_rotation(&stacks->a, &stacks->b);
	move_stacks(&stacks->a, &stacks->b, best_b_rot(&stacks->b, get_max(&stacks->b)), 'b');
	while (stacks->b.len > 0)
		push_lst(&stacks->a, &stacks->b, "b to a", 'a');
}
