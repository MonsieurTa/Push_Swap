/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 21:00:25 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 07:40:59 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "push_swap.h"
#include "operations.h"

void	do_push_n_swap(t_stacks *stacks, t_node *op)
{
	if (op->value == 0)
		push_lst(&stacks->a, &stacks->b, "b to a", 0);
	else if (op->value == 1)
		push_lst(&stacks->a, &stacks->b, "a to b", 0);
	else if (op->value == 2)
		swap(&stacks->a, 0);
	else if (op->value == 3)
		swap(&stacks->b, 0);
	else if (op->value == 4)
		sswap(&stacks->a, &stacks->b, "");
}

void	do_rot(t_stacks *stacks, t_node *op)
{
	if (op->value == 5)
		rot(&stacks->a, 0);
	else if (op->value == 6)
		rot(&stacks->b, 0);
	else if (op->value == 7)
		rrot(&stacks->a, &stacks->b, "");
	else if (op->value == 8)
		rev_rot(&stacks->a, 0);
	else if (op->value == 9)
		rev_rot(&stacks->b, 0);
	else if (op->value == 10)
		rrev_rot(&stacks->a, &stacks->b, "");
}

void	do_op(t_stacks *stacks, t_lst *op, int flag)
{
	t_node	*node;
	char	*line;
	int		max;
	int		idx;

	node = op->head;
	idx = 0;
	max = get_max(&stacks->a);
	if ((flag == 1 && (line = create_line(stacks, max)) == NULL))
		return ;
	while (idx < op->len)
	{
		if (flag == 1)
		{
			system("clear");
			visu(stacks, line, max);
			usleep(1000 * 50);
		}
		do_push_n_swap(stacks, node);
		do_rot(stacks, node);
		node = node->next;
		idx++;
	}
	if (flag == 1)
	{
		system("clear");
		visu(stacks, line, max);
		ft_strdel(&line);
	}
}
