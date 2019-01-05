/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:37:43 by wta               #+#    #+#             */
/*   Updated: 2019/01/05 04:12:19 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "link_list.h"
#include "push_swap.h"
#include "operations.h"

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

int	add_to_stack(t_lst *a, char **split)
{
	t_node	*node;
	int		idx;

	idx = 0;
	while (split[idx] != NULL)
	{
		//TODO check if digit
		if ((node = newnode(ft_atoi(split[idx]))) != NULL)
			pushback(a, node);
		else
		{
			rm_lst(a);
			ft_delsplit(split);
			return (0);
		}
		idx++;
	}
	ft_delsplit(split);
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
		while (c++ < lst->head->value)
			ft_putchar('.');
		ft_putchar('\n');
		lst->head = lst->head->next;
		idx++;
	}
	ft_printf("\n");
}
