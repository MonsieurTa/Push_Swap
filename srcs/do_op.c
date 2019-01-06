/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 21:00:25 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 01:19:01 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "push_swap.h"
#include "operations.h"

void	do_push_n_swap(t_stacks *stacks, char *line)
{
	if (ft_strequ(line, "pa") == 1)
		push_lst(&stacks->a, &stacks->b, "b to a", 0);
	else if (ft_strequ(line, "pb") == 1)
		push_lst(&stacks->a, &stacks->b, "a to b", 0);
	else if (ft_strequ(line, "sa") == 1)
		swap(&stacks->a, 0);
	else if (ft_strequ(line, "sb") == 1)
		swap(&stacks->b, 0);
	else if (ft_strequ(line, "ss") == 1)
		sswap(&stacks->a, &stacks->b, "");
}

void	do_rot(t_stacks *stacks, char *line)
{
	if (ft_strequ(line, "ra") == 1)
		rot(&stacks->a, 0);
	else if (ft_strequ(line, "rb") == 1)
		rot(&stacks->b, 0);
	else if (ft_strequ(line, "rr") == 1)
		rrot(&stacks->a, &stacks->b, "");
	else if (ft_strequ(line, "rra") == 1)
		rev_rot(&stacks->a, 0);
	else if (ft_strequ(line, "rrb") == 1)
		rev_rot(&stacks->b, 0);
	else if (ft_strequ(line, "rrr") == 1)
		rrev_rot(&stacks->a, &stacks->b, "");
}

int		check_op(char *line)
{
	int	ret;

	ret = 0;
	if (ft_strequ(line, "pa") == 1 || ft_strequ(line, "pb") == 1
	|| ft_strequ(line, "sa") == 1 || ft_strequ(line, "sb") == 1
	|| ft_strequ(line, "ss") == 1 || ft_strequ(line, "ra") == 1
	|| ft_strequ(line, "rb") == 1 || ft_strequ(line, "rr") == 1
	|| ft_strequ(line, "rra") == 1 || ft_strequ(line, "rrb") == 1
	|| ft_strequ(line, "rrr") == 1)
		return (1);
	ft_strdel(&line);
	return (0);
}

int		do_op(t_stacks *stacks)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (check_op(line) == 0)
			return (0);
		do_push_n_swap(stacks, line);
		do_rot(stacks, line);
		ft_strdel(&line);
	}
	return (1);
}
