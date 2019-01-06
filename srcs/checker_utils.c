/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:35:24 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 10:36:38 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "link_list.h"
#include "push_swap.h"
#include "operations.h"

int		check_stacks(t_stacks *stacks)
{
	if (stacks->b.head == NULL)
	{
		if (is_sort(&stacks->a) == 1)
		{
			ft_printf("OK\n");
			return (1);
		}
	}
	return (0);
}

int		get_push_n_swap(t_lst *op, char *line)
{
	t_node	*node;

	node = NULL;
	if (ft_strequ(line, "pa") == 1 && (node = newnode(0)) != NULL)
		pushback(op, node);
	else if (ft_strequ(line, "pb") == 1 && (node = newnode(1)) != NULL)
		pushback(op, node);
	else if (ft_strequ(line, "sa") == 1 && (node = newnode(2)) != NULL)
		pushback(op, node);
	else if (ft_strequ(line, "sb") == 1 && (node = newnode(3)) != NULL)
		pushback(op, node);
	else if (ft_strequ(line, "ss") == 1 && (node = newnode(4)) != NULL)
		pushback(op, node);
	return (node != NULL);
}
