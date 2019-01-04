/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:49:22 by wta               #+#    #+#             */
/*   Updated: 2019/01/04 06:26:34 by wta              ###   ########.fr       */
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

void	smallest_rotation(t_lst *b, int value)
{
	int	opti;
	int	len;
	int	mid;

	len = d_from_max(b, value) - d_from_max(b, b->head->value);
	mid = (b->len % 2 == 0) ? 1 + b->len / 2 : b->len / 2;
	opti = (len < 0) ? b->len - ft_abs(len) : len - b->len;
	if (ft_abs(opti) <= b->len / 2)
		len = opti;
	if (len > 0)
	{
		while (len-- > 0)
			rotate(b);
	}
	else
	{
		while (len++ < 0)
			reverse_rotate(b);
	}
}

void	insert(t_lst *a, t_lst *b)
{
	smallest_rotation(b, a->head->value);
	push_lst(a, b, "a to b");
}

void	small_sort(t_lst *b)
{
	while (is_sort_from_h(b) == 0)
	{
		if (b->head->next->value > b->head->value)
			swap(b);
		else if (b->tail->value > b->head->value)
			reverse_rotate(b);
		else if (b->head->next->value < b->tail->value)
			reverse_rotate(b);
	}
}

void	selection_sort(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i++ < 3)
		push_lst(&stacks->a, &stacks->b, "a to b");
	small_sort(&stacks->b);
	while (stacks->a.len > 0)
		insert(&stacks->a, &stacks->b);
	smallest_rotation(&stacks->b, get_max(&stacks->b));
	while (stacks->b.len > 0)
		push_lst(&stacks->a, &stacks->b, "b to a");
}
