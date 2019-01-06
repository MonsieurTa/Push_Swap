/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 01:05:33 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 09:55:02 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/includes/ft_printf.h"
#include "link_list.h"
#include "operations.h"
#include "push_swap.h"

int		fit_in(int value_a, t_node *node_b)
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

int		best_a_rot(t_lst *a, t_lst *b)
{
	t_node	*node;
	int		len;
	int		mid;

	len = 0;
	node = a->head;
	mid = a->len / 2;
	while (len < a->len && fit_in(node->value, b->head) == 0)
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
	if (rot > stack->len / 2)
		rot = rot - stack->len;
	return (rot);
}

void	set_opti_rot(t_stacks *stacks, char *str, int i, int j)
{
	int	*ptr_a;
	int	*ptr_b;
	int	rot_type;

	rot_type = ft_strequ(str, "double");
	ptr_a = (rot_type == 1) ? &stacks->rrr_rot : &stacks->a_rot;
	ptr_b = (rot_type == 1) ? &stacks->rb_rot : &stacks->b_rot;
	if (ft_abs(opti_rot(&stacks->a, i)) + ft_abs(
				opti_rot(&stacks->b, j)) < ft_abs(*ptr_a) + ft_abs(*ptr_b))
	{
		*ptr_a = (rot_type == 1) ? i : opti_rot(&stacks->a, i);
		*ptr_b = opti_rot(&stacks->b, j);
	}
}
