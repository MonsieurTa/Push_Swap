/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 01:04:11 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 09:54:18 by wta              ###   ########.fr       */
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
	int		i;

	i = -1;
	node = b->head;
	value = node->value;
	while (++i < b->len)
	{
		if (value < node->value)
			value = node->value;
		node = node->next;
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
		{
			if (c == 'a' || c == 'b')
				rot((c == 'b') ? b : a, c);
			else if (c == 'x')
				rrot(a, b, "rr");
		}
	}
	else
	{
		while (len++ < 0)
		{
			if (c == 'a' || c == 'b')
				rev_rot((c == 'b') ? b : a, c);
			else if (c == 'x')
				rrev_rot(a, b, "rrr");
		}
	}
}

int		best_b_rot(t_lst *b, int value)
{
	int	opti;
	int	len;

	len = d_from_max(b, value) - d_from_max(b, b->head->value);
	opti = (len < 0) ? b->len - ft_abs(len) : len - b->len;
	if (ft_abs(opti) <= b->len / 2)
		len = opti;
	return (len);
}
