/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:07:22 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 09:53:58 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "link_list.h"

t_node	*newnode(int value)
{
	t_node	*node;

	node = NULL;
	if ((node = ft_memalloc(sizeof(t_node))) != NULL)
	{
		node->next = NULL;
		node->prev = NULL;
		node->value = value;
	}
	return (node);
}

void	pushfront(t_lst *lst, t_node *node)
{
	if (node != NULL)
	{
		if (lst->len == 0)
		{
			lst->head = node;
			lst->tail = node;
		}
		else
		{
			node->next = lst->head;
			lst->head->prev = node;
			lst->head = node;
		}
		lst->head->prev = lst->tail;
		lst->tail->next = lst->head;
		lst->len += 1;
	}
}

void	pushback(t_lst *lst, t_node *node)
{
	if (node != NULL)
	{
		if (lst->len == 0)
		{
			lst->head = node;
			lst->tail = node;
		}
		else
		{
			node->prev = lst->tail;
			lst->tail->next = node;
			lst->tail = node;
		}
		lst->head->prev = lst->tail;
		lst->tail->next = lst->head;
		lst->len += 1;
	}
}

t_node	*pop_front(t_lst *lst)
{
	t_node *node;

	node = NULL;
	if (lst->len > 0)
	{
		node = lst->head;
		if (lst->len == 1)
		{
			lst->head = NULL;
			lst->tail = NULL;
		}
		else
		{
			lst->head = lst->head->next;
			lst->head->prev = lst->tail;
			lst->tail->next = lst->head;
		}
		lst->len -= 1;
		node->next = NULL;
		node->prev = NULL;
	}
	return (node);
}

int		rm_lst(t_lst *lst)
{
	t_node	*tmp;

	while (lst->len > 0)
	{
		tmp = pop_front(lst);
		free(tmp);
		tmp = NULL;
	}
	return (0);
}
