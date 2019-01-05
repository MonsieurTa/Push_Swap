/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:44:56 by wta               #+#    #+#             */
/*   Updated: 2019/01/04 23:24:52 by wta              ###   ########.fr       */
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

void	print_tab(int *tab, int len)
{
	for (int i = 0 ; i < len; i++)
		ft_printf("tab value %d\n", tab[i]);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	init_lst(&stacks.a);
	init_lst(&stacks.b);
	if (read_args(ac, av, &stacks.a) == 0)
		return (0);
//	print_tab(tab.tab, tab.len);
	selection_sort(&stacks);
	print_list(&stacks.a);
//	insertion_sort(&stacks.a, &stacks.b, &tab);
//	quicksort(&stacks, &tab, 0, tab.len - 1);
	return (0);
}
