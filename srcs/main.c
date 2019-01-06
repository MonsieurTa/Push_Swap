/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:44:56 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 04:55:37 by wta              ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_stacks	stacks;

	init_stacks(&stacks);
	if (read_args(ac, av, &stacks.a) == 0)
		return (0);
	else if (stacks.a.len <= 3)
		small_sort(&stacks.a, 'a');
	else if (is_sort(&stacks.a) == 0 && stacks.a.len <= 15)
		insertion_sort(&stacks);
	else if (is_sort(&stacks.a) == 0)
		selection_sort(&stacks);
	rm_lst(&stacks.a);
	return (0);
}
