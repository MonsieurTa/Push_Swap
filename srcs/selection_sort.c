/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:49:22 by wta               #+#    #+#             */
/*   Updated: 2019/01/05 23:17:58 by wta              ###   ########.fr       */
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
				rrev_rot(a, b,  "rrr");
		}
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
	if (*ptr_a == -1 && *ptr_b == -1)
	{
		*ptr_a = (rot_type == 1) ? i : opti_rot(&stacks->a, i);
		*ptr_b = opti_rot(&stacks->b, j);
	}
	else if (ft_abs(opti_rot(&stacks->a, i)) + ft_abs(
				opti_rot(&stacks->b, j)) < ft_abs(*ptr_a) + ft_abs(*ptr_b))
	{
		*ptr_a = (rot_type == 1) ? i : opti_rot(&stacks->a, i);
		*ptr_b = opti_rot(&stacks->b, j);
	}
}

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
			if (fit_in_b(node_a->value, tmp_b) == 1)
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
			if (fit_in_b(node_a->value, node_b) == 1)
				set_opti_rot(stacks, "single", i, j);
			node_b = node_b->next;
		}
		node_a = node_a->next;
	}
}

void	two_stack_rot(t_stacks *stacks)
{
	*(&stacks->rrr_rot) = -1;
	*(&stacks->rb_rot) = -1;
	*(&stacks->a_rot) = -1;
	*(&stacks->b_rot) = -1;
	get_double_rot(stacks);
	get_two_rot(stacks);
	if (ft_abs(stacks->rrr_rot) + ft_abs(stacks->rb_rot) < ft_abs(stacks->a_rot) + ft_abs(stacks->b_rot))
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

void	insert(t_stacks *stacks)
{
	two_stack_rot(stacks);
	push_lst(&stacks->a, &stacks->b, "a to b", 'b');
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
		insert(stacks);
	move_stacks(&stacks->a, &stacks->b, best_b_rot(&stacks->b,
		get_max(&stacks->b)), 'b');
	while (stacks->b.len > 0)
		push_lst(&stacks->a, &stacks->b, "b to a", 'a');
}
