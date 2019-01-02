/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:44:56 by wta               #+#    #+#             */
/*   Updated: 2019/01/01 18:31:48 by wta              ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_inttab	inttab;

	if ((inttab.len = read_args(ac, av, &inttab)) != 0)
	{
		quicksort_tab(inttab.tab, 0, inttab.len - 1);
		for (int i = 0 ; i < inttab.len; i++)
			ft_printf("value = %d\n", inttab.tab[i]);
	}
	return (0);
}
