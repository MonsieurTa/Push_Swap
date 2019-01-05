/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 14:13:22 by wta               #+#    #+#             */
/*   Updated: 2019/01/04 22:30:19 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"
#include <stdlib.h>
#include <unistd.h>

int		unsorted_from_min(t_lst *lst, int min)
{
	t_node	*node;
	int		count;
	int		i;

	count = 0;
	if (lst != NULL && lst->len >= 2)
	{
		node = lst->head;
		while (node->value != min)
			node = node->next;
		i = 0;
		while (i < lst->len - 1)
		{
			if (node->value > node->next->value)
				count++;
			node = node->next;
			i++;
		}
	}
	return (count);
}

int	pos_in_tab(t_tab *tab, int value)
{
	int	i;

	i = 0;
	while (i < tab->len)
	{
		if (value == tab->tab[i])
			return (i);
		i++;
	}
	return (-1);
}

int	pos_in_lst(t_lst *lst, t_node *node, int min)
{
	t_node	*tmp;
	int		pos;

	if (lst != NULL)
	{
		tmp = lst->head;
		while (tmp->value != min)
			tmp = tmp->next;
		pos = 0;
		while (tmp != node)
		{
			tmp = tmp->next;
			pos++;
		}
		return (pos);
	}
	return (-1);
}

void	nearest_rotation(t_lst *lst, t_tab *tab, int value)
{
	int		lst_pos;
	int		tab_pos;
	int		dr;
	int		dl;

	tab_pos = pos_in_tab(tab, value);
	lst_pos = pos_in_lst(lst, lst->head, tab->tab[0]);
	dr = 0;
	while ((lst_pos + dr) % (tab->len) != tab_pos)
		dr++;
	dl = 0;
	while ((lst_pos - dl) != tab_pos)
	{
		if (lst_pos - dl < 0)
			if ((tab->len) + (lst_pos - dl) == tab_pos)
				break ;
		dl++;
	}
	if (dr != 0 && dl != 0)
	{
		if (dr < dl)
		{
			while (dr-- > 0)
				rot(lst, 'b');
		}
		else
			while (dl-- > 0)
				rev_rot(lst, 'b');
	}
}

int		correct_place(t_lst *lst, t_tab *tab, t_node *node)
{
	return (pos_in_lst(lst, node, tab->tab[0]) == pos_in_tab(tab, node->value));
}

void	find_unsorted(t_lst *lst, t_tab *tab)
{
	t_node	*node;
	t_node	*prev;
	int		i;
	int		ret;

	node = lst->head;
	if ((ret = correct_place(lst, tab, node)) == 0)
		return ;
	i = 0;
	while (++i < lst->len - 1)
	{
		node = node->next;
		prev = node->prev;
		if (correct_place(lst, tab, node) == 0)
		{
			while (i-- > 0)
				rot(lst, 'b');
			return ;
		}
		else if (correct_place(lst, tab, prev) == 0)
		{
			while (i-- > 0)
				rev_rot(lst, 'b');
			return ;
		}
	}
}

int	d_from_min(t_lst *lst, t_node *node, int min)
{
	t_node	*tmp;
	int		idx;

	tmp = lst->head;
	while (tmp->value != min)
		tmp = tmp->next;
	idx = 0;
	while (tmp != node)
	{
		tmp = tmp->next;
		idx++;
	}
	return (idx);
}

int	pre_sort(t_lst *lst, t_tab *tab)
{
	if (lst->head->value == tab->tab[tab->len - 1]
	&& lst->head->next->next->value == tab->tab[0])
		swap(lst, 'b');
	else if (d_from_min(lst, lst->head->next, tab->tab[0]) - 1 == pos_in_tab(tab,
	lst->head->next->value))
		swap(lst, 'b');
	else if (d_from_min(lst, lst->tail, tab->tab[0]) + 1 == pos_in_tab(tab,
	lst->tail->value))
		rot(lst, 'b');
	else if (d_from_min(lst, lst->head, tab->tab[0]) - 1 == pos_in_tab(tab,
	lst->head->value))
		rev_rot(lst, 'b');
	else
		return (0);
	return (1);
}

void	insertion_sort(t_lst *lst, t_lst *stack, t_tab *tab)
{
	while (unsorted_from_min(lst, tab->tab[0]) != 0)
	{
		if (pre_sort(lst, tab) == 0)
		{
			find_unsorted(lst, tab);
			push_lst(lst, stack, "a to b", 'b');
			nearest_rotation(lst, tab, stack->head->value);
			push_lst(lst, stack, "b to a", 'a');
		}
	}
	nearest_rotation(lst, tab, tab->tab[0]);
}
