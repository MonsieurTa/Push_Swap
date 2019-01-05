/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:37:43 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 00:19:10 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "link_list.h"
#include "push_swap.h"
#include "operations.h"

void	init_stacks(t_stacks *stacks)
{
	init_lst(&stacks->a);
	init_lst(&stacks->b);
}

void	ft_delsplit(char **split)
{
	int		idx;

	if (split)
	{
		idx = 0;
		while (split[idx] != NULL)
		{
			free(split[idx]);
			split[idx] = NULL;
			idx++;
		}
		free(split);
		split = NULL;
	}
}

int	is_num(char *str)
{
	int	idx;

	if (str)
	{
		idx = (str[0] == '-' || str[0] == '+') ? 1 : 0;
		if (str[idx] == '\0')
			return (0);
		while (str[idx] >= '0' && str[idx] <= '9')
			idx++;
		if (str[idx == '\0'])
			return (1);
	}
	return (0);
}

long long	ft_atoi_ll(char *str)
{
	long long	res;
	char		sign;
	int			i;

	res = 0;
	i = (str[0] == '-' | str[0] == '+') ? 1 : 0;
	sign = (str[0] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	check_split(char **split)
{
	long long	value;
	int			idx;

	idx = 0;
	while (split[idx] != NULL)
	{
		if (is_num(split[idx]) == 0)
			return (0);
		value = ft_atoi_ll(split[idx]);
		if (value < -2147483648 || value > 2147483647)
			return (0);
		idx++;
	}
	return (1);
}

int	is_in_list(t_lst *a, int value)
{
	t_node	*node;
	int		i;

	node = a->head;
	if (node != NULL)
	{
		i = 0;
		while (i < a->len)
		{
			if (value == node->value)
				return (1);
			node = node->next;
			i++;
		}
	}
	return (0);
}

int	add_to_stack(t_lst *a, char **split)
{
	t_node	*node;
	int		idx;
	int		ret;

	idx = 0;
	if ((ret = check_split(split)) == 1)
	{
		while (ret == 1 && split[idx] != NULL)
		{
			if (is_in_list(a, ft_atoi(split[idx])) == 0)
			{
				if ((node = newnode(ft_atoi(split[idx]))) != NULL)
					pushback(a, node);
				else
					ret = 0;
			}
			else
				ret = 0;
			idx++;
		}
	}
	if (ret == 0)
		rm_lst(a);
	ft_delsplit(split);
	return (ret);
}

int		is_sort(t_lst *lst)
{
	t_node	*node;
	int		i;

	node = lst->head;
	if (node != NULL)
	{
		i = 0;
		while (i < lst->len - 1)
		{
			if (node->value > node->next->value)
				return (0);
			node = node->next;
			i++;
		}
	}
	return (1);
}

void	print_list(t_lst *lst, char c)
{
	int	idx;

	idx = 0;
	ft_printf("%c STACK :\n", c);
	while (idx < lst->len)
	{
		c = 0;
		ft_printf("%d ", lst->head->value);
		lst->head = lst->head->next;
		idx++;
	}
	ft_printf("\n");
}
