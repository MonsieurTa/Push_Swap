/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:48:26 by wta               #+#    #+#             */
/*   Updated: 2019/01/05 23:19:30 by wta              ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		**split;
	int			idx;
	int			ret;

	ret = 1;
	if (ac > 1)
	{
		init_stacks(&stacks);
		idx = 1;
		while (ret == 1 && idx < ac)
		{
			if ((split = ft_strsplit(av[idx], ' ')) != NULL
			&& add_to_stack(&stacks.a, split) == 0)
				ret = 0;
			else if (split == NULL)
				ret = 0;
			idx++;
		}
		if (ret == 0 || do_op(&stacks) == 0)
			ft_putstr_fd("Error\n", 2);
		else if (check_stacks(&stacks) == 0)
			ft_printf("KO\n");
		rm_lst(&stacks.a);
		rm_lst(&stacks.b);
	}
	return (0);
}
