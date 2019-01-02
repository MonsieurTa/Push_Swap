/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 18:25:41 by wta               #+#    #+#             */
/*   Updated: 2018/12/30 20:11:38 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "link_list.h"
#include "operations.h"

void	bubble_sort(t_lst *lst)
{
	t_node	*node;
	int		idx;

	idx = 0;
	while (idx < lst->len)
	{
		node = lst->head;
		if (idx != lst->len - 1 && node->value > node->next->value)
		{
			swap(lst);
			ft_printf("sa\n");
			if (idx > 0)
			{
				idx -= 1;
				reverse_rotate(lst);
				ft_printf("rra\n");
			}
		}
		else
		{
			idx++;
			rotate(lst);
			ft_printf("ra\n");
		}
	}
}
