/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:37:43 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 01:00:28 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "link_list.h"
#include "push_swap.h"
#include "operations.h"

void	init_stacks(t_stacks *stacks)
{
	init_lst(&stacks->a);
	init_lst(&stacks->b);
}

int		check_split(char **split)
{
	long long	value;
	int			idx;

	idx = 0;
	while (split[idx] != NULL)
	{
		if (is_num(split[idx]) == 0)
			return (0);
		value = ft_atoi_ll(split[idx]);
		if (value < -2147483648 || value > 2147483647)
			return (0);
		idx++;
	}
	return (idx > 0);
}

int		is_in_list(t_lst *a, int value)
{
	t_node	*node;
	int		i;

	node = a->head;
	if (node != NULL)
	{
		i = 0;
		while (i < a->len)
		{
			if (value == node->value)
				return (1);
			node = node->next;
			i++;
		}
	}
	return (0);
}

int		add_to_stack(t_lst *a, char **split)
{
	t_node	*node;
	int		idx;
	int		ret;

	idx = 0;
	if ((ret = check_split(split)) == 1)
	{
		while (ret == 1 && split[idx] != NULL)
		{
			if (is_in_list(a, ft_atoi(split[idx])) == 0)
			{
				if ((node = newnode(ft_atoi(split[idx]))) != NULL)
					pushback(a, node);
				else
					ret = 0;
			}
			else
				ret = 0;
			idx++;
		}
	}
	if (ret == 0)
		rm_lst(a);
	ft_delsplit(split);
	return (ret);
}

int		is_sort(t_lst *lst)
{
	t_node	*node;
	int		i;

	node = lst->head;
	if (node != NULL)
	{
		i = 0;
		while (i < lst->len - 1)
		{
			if (node->value > node->next->value)
				return (0);
			node = node->next;
			i++;
		}
	}
	return (1);
}
