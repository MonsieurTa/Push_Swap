/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 10:05:25 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 10:05:27 by wta              ###   ########.fr       */
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
	else if (is_sort(&stacks.a) == 0 && stacks.a.len <= 5)
		insertion_sort(&stacks);
	else if (is_sort(&stacks.a) == 0)
		selection_sort(&stacks);
	rm_lst(&stacks.a);
	return (0);
}
