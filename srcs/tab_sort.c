/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:58:29 by wta               #+#    #+#             */
/*   Updated: 2019/01/03 22:16:14 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab_sort.h"

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
