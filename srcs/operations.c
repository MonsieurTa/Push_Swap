/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:28:31 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 01:15:06 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "link_list.h"
#include "operations.h"

void	swap(t_lst *lst, char c)
{
	t_node	*node;
	int		tmp;

	if (lst->len >= 2)
	{
		node = lst->head;
		tmp = node->value;
		node->value = node->next->value;
		node->next->value = tmp;
		if (c == 'a' || c == 'b')
			ft_printf("s%c\n", c);
	}
}

void	push_lst(t_lst *a, t_lst *b, char *str, char c)
{
	t_node	*node;
	int		comp;

	comp = ft_strequ(str, "a to b");
	if ((comp == 1) ? a && a->len > 0 : b && b->len > 0)
	{
		if ((node = pop_front((comp == 1) ? a : b)) != NULL)
		{
			pushfront((comp == 1) ? b : a, node);
			if (c == 'b' || c == 'a')
				ft_printf("p%c\n", c);
		}
	}
}

void	rot(t_lst *lst, char c)
{
	if (lst && lst->len >= 2)
	{
		lst->head = lst->head->next;
		lst->tail = lst->tail->next;
		if (c == 'a' || c == 'b')
			ft_printf("r%c\n", c);
	}
}
