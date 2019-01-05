/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:48:26 by wta               #+#    #+#             */
/*   Updated: 2019/01/05 17:48:39 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "link_list.h"
#include "push_swap.h"
#include "operations.h"



int	do_op(t_stacks *stacks)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		system("clear");
		if (ft_strequ(line, "sa") == 1)
			swap(&stacks->a, 0);
		else if (ft_strequ(line, "sb") == 1)
			swap(&stacks->b, 0);
		else if (ft_strequ(line, "ss") == 1)
			sswap(&stacks->a, &stacks->b, 0);
		else if (ft_strequ(line, "pa") == 1)
			push_lst(&stacks->a, &stacks->b, "b to a", 0);
		else if (ft_strequ(line, "pb") == 1)
			push_lst(&stacks->a, &stacks->b, "a to b", 0);
		else if (ft_strequ(line, "ra") == 1)
			rot(&stacks->a, 0);
		else if (ft_strequ(line, "rb") == 1)
			rot(&stacks->b, 0);
		else if (ft_strequ(line, "rr") == 1)
			rrot(&stacks->a, &stacks->b, 0);
		else if (ft_strequ(line, "rra") == 1)
			rev_rot(&stacks->a, 0);
		else if (ft_strequ(line, "rrb") == 1)
			rev_rot(&stacks->b, 0);
		else if (ft_strequ(line, "rrr") == 1)
			rrev_rot(&stacks->a, &stacks->b, 0);
		ft_printf("exec: %s\n", line);
		print_list(&stacks->a, 'A');
		print_list(&stacks->b, 'B');
		usleep(1000*50);
		ft_strdel(&line);
	}
	system("clear");
	return (1);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		**split;
	int			idx;

	if (ac > 1)
	{
		init_stacks(&stacks);
		idx = 1;
		while (idx < ac)
		{
			if ((split = ft_strsplit(av[idx], ' ')) != NULL
			&& add_to_stack(&stacks.a, split) == 0)
				return (0);
			else if (split == NULL)
				return (rm_lst(&stacks.a));
			idx++;
		}
		do_op(&stacks);
		print_list(&stacks.a, 'X');
		rm_lst(&stacks.a);
	}
	return (0);
}
