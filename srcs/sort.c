/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 14:13:22 by wta               #+#    #+#             */
/*   Updated: 2019/01/01 18:35:54 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link_list.h"
#include "push_swap.h"

void	init_lst_info(t_lst_info *info)
{
	info->sorted_h = 0;
	info->sorted_t = 0;
}

int		is_sort(t_lst *lst, t_lst_info *info)
{
	t_node	*node;

	if (lst->len > 0)
	{
		init_lst_info(info);
		node = lst->head;
		while (node->value < node->next->value)
		{
			node = node->next;
			info->sorted_h += 1;
		}
		if (info->sorted_h == lst->len - 1)
			return (1);
		node = lst->tail;
		while (node->value > node->prev->value)
		{
			node = node->prev;
			info->sorted_t += 1;
		}
	}
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quicksort_tab(int *tab, int start, int end)
{
	int	pivot;
	int	split;
	int	idx;

	if (start >= end)
		return ;
	pivot = tab[end];
	split = start;
	idx = start;
	while (idx <= end)
	{
		if (tab[idx] <= pivot)
		{
			ft_swap(&tab[split], &tab[idx]);
			split++;
		}
		idx++;
	}
	quicksort_tab(tab, start, split - 2);
	quicksort_tab(tab, split, end);
}
