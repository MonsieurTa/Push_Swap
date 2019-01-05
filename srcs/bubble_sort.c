/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 18:25:41 by wta               #+#    #+#             */
/*   Updated: 2019/01/04 22:27:46 by wta              ###   ########.fr       */
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
			swap(lst, 'a');
			if (idx > 0)
			{
				idx -= 1;
				rev_rot(lst, 'a');
			}
		}
		else
		{
			idx++;
			rot(lst, 'a');
		}
	}
}
