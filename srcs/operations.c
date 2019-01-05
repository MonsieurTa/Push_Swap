/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:28:31 by wta               #+#    #+#             */
/*   Updated: 2019/01/04 23:33:07 by wta              ###   ########.fr       */
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

	if (ft_strequ(str, "a to b") == 1)
	{
		if (a && a->len > 0)
		{
			if ((node = pop_front(a)) != NULL)
			{
				pushfront(b, node);
				if (c == 'b')
					ft_printf("p%c\n", c);
			}
		}
	}
	else if (ft_strequ(str, "b to a") == 1)
	{
		if (b && b->len > 0)
		{
			if ((node = pop_front(b)) != NULL)
			{
				pushfront(a, node);
				if (c == 'a')
					ft_printf("p%c\n", c);
			}
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

void	rev_rot(t_lst *lst, char c)
{
	if (lst && lst->len >= 2)
	{
		lst->head = lst->head->prev;
		lst->tail = lst->tail->prev;
		if (c == 'a' || c == 'b')
			ft_printf("rr%c\n", c);
	}
}

void	sswap(t_lst *a, t_lst *b, char *str)
{
	swap(a, 0);
	swap(b, 0);
	if (ft_strequ(str, "ss"))
		ft_printf("ss\n");
}

void	rrot(t_lst *a, t_lst *b, char *str)
{
	rot(a, 0);
	rot(b, 0);
	if (ft_strequ(str, "rr"))
		ft_printf("rr\n");
}

void	rrev_rot(t_lst *a, t_lst *b, char *str)
{
	rev_rot(a, 0);
	rev_rot(b, 0);
	if (ft_strequ(str, "rrr"))
		ft_printf("rrr\n");
}
