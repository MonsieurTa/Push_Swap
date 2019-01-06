/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 04:58:52 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 05:00:07 by wta              ###   ########.fr       */
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

int		fit_in_a(int value, t_node *node)
{
	if (node->prev->value > node->value)
	{
		if (value < node->value
		|| value > node->prev->value)
			return (1);
	}
	else
	{
		if (value < node->value && value > node->prev->value)
			return (1);
	}
	return (0);
}

void	get_opti_rot(t_stacks *stacks, char *str, int i, int j)
{
	int	*ptr_a;
	int	*ptr_b;
	int	rot_type;

	rot_type = ft_strequ(str, "double");
	ptr_a = (rot_type == 1) ? &stacks->rrr_rot : &stacks->a_rot;
	ptr_b = (rot_type == 1) ? &stacks->rb_rot : &stacks->b_rot;
	if (ft_abs(opti_rot(&stacks->a, j)) + ft_abs(
				opti_rot(&stacks->b, i)) < ft_abs(*ptr_a) + ft_abs(*ptr_b))
	{
		*ptr_a = opti_rot(&stacks->a, j);
		*ptr_b = (rot_type == 1) ? i : opti_rot(&stacks->b, i);
	}
}

void	double_rot(t_stacks *stacks)
{
	t_node	*node_a;
	t_node	*node_b;
	t_node	*tmp_a;
	int		i;
	int		j;

	node_a = stacks->a.head;
	node_b = stacks->b.head;
	i = -1;
	while (++i < stacks->b.len)
	{
		tmp_a = node_a;
		j = -1;
		while (++j < stacks->a.len)
		{
			if (fit_in_a(node_b->value, tmp_a) == 1)
				get_opti_rot(stacks, "double", i, j);
			tmp_a = tmp_a->next;
		}
		node_a = node_a->next;
		node_b = node_b->next;
	}
}
