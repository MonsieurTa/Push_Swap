/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:48:26 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 10:43:17 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "link_list.h"
#include "push_swap.h"
#include "operations.h"

int		get_rot(t_lst *op, char *line)
{
	t_node	*node;

	node = NULL;
	if (ft_strequ(line, "ra") == 1 && (node = newnode(5)) != NULL)
		pushback(op, node);
	else if (ft_strequ(line, "rb") == 1 && (node = newnode(6)) != NULL)
		pushback(op, node);
	else if (ft_strequ(line, "rr") == 1 && (node = newnode(7)) != NULL)
		pushback(op, node);
	else if (ft_strequ(line, "rra") == 1 && (node = newnode(8)) != NULL)
		pushback(op, node);
	else if (ft_strequ(line, "rrb") == 1 && (node = newnode(9)) != NULL)
		pushback(op, node);
	else if (ft_strequ(line, "rrr") == 1 && (node = newnode(10)) != NULL)
		pushback(op, node);
	return (node != NULL);
}

int		get_op(t_lst *op)
{
	char	*line;
	int		gnl_ret;

	init_lst(op);
	while ((gnl_ret = get_next_line(0, &line)) > 0)
	{
		if (get_push_n_swap(op, line) == 0)
		{
			if (get_rot(op, line) == 0)
			{
				ft_strdel(&line);
				rm_lst(op);
				return (0);
			}
		}
		ft_strdel(&line);
	}
	return (1);
}

void	check_all(t_stacks *stacks, t_lst *op, int ret, char *flag)
{
	int	v;

	v = ft_strequ(flag, "-v");
	if (ret == 0 || get_op(op) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	do_op(stacks, op, v == 1);
	if (check_stacks(stacks) == 0)
		ft_printf("KO\n");
	rm_lst(&stacks->a);
	rm_lst(&stacks->b);
	rm_lst(op);
}

int		check_opt(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strequ(av[1], "-v") == 1)
		{
			ft_putstr_fd("usage: ./checker [-v] [...]\n", 2);
			return (0);
		}
	}
	if (ac > 2)
	{
		if (ft_strequ(av[1], "-v") == 1)
			return (2);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_stacks	stacks;
	t_lst		op;
	char		**split;
	int			idx;
	int			ret;

	ret = 1;
	if (ac > 1)
	{
		init_stacks(&stacks);
		if ((idx = check_opt(ac, av)) > 0)
		{
			while (ret == 1 && idx < ac)
			{
				if ((split = ft_strsplit(av[idx], ' ')) != NULL
						&& add_to_stack(&stacks.a, split) == 0)
					ret = 0;
				else if (split == NULL)
					ret = 0;
				idx++;
			}
			check_all(&stacks, &op, ret, av[1]);
		}
	}
	return (0);
}
