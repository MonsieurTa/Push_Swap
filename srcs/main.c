/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:44:56 by wta               #+#    #+#             */
/*   Updated: 2019/01/03 04:11:23 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/includes/ft_printf.h"
#include "link_list.h"
#include "operations.h"
#include "push_swap.h"
#include "read.h"

void	print_list(t_lst *lst)
{
	int	idx;
	ft_printf("LST LEN = %d\n", lst->len);
	idx = 0;
	while (idx < lst->len)
	{
		ft_printf("idx = %d --- value = %d\n", idx, lst->head->value);
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
	t_tab	tab;
	t_lst	lst;	
	t_lst	stack;

	init_lst(&stack);
	if ((tab.len = read_args(ac, av, &tab, &lst)) != 0)
		quicksort_tab(tab.tab, 0, tab.len - 1);
	insertion_sort(&lst, &stack, &tab);
	print_list(&lst);
	return (0);
}
