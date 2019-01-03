/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:44:56 by wta               #+#    #+#             */
/*   Updated: 2019/01/03 22:12:10 by wta              ###   ########.fr       */
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

void	print_list(t_lst *lst)
{
	int	idx;
	ft_printf("LST LEN = %d\n", lst->len);
	idx = 0;
	while (idx < lst->len)
	{
		ft_printf("%d\n", lst->head->value);
		lst->head = lst->head->next;
		idx++;
	}
}

void	print_tab(int *tab, int len)
{
	for (int i = 0 ; i < len; i++)
		ft_printf("tab value %d\n", tab[i]);
}

int	main(int ac, char **av)
{
	t_tab		tab;
	t_stacks	stacks;

	init_lst(&stacks.a);
	init_lst(&stacks.b);
	if ((tab.len = read_args(ac, av, &tab, &stacks.a)) != 0)
		quicksort_tab(tab.tab, 0, tab.len - 1);
//	print_tab(tab.tab, tab.len);
	insertion_sort(&stacks.a, &stacks.b, &tab);
//	quicksort(&stacks, &tab, 0, tab.len - 1);
	return (0);
}
