/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 05:58:14 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 06:52:20 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include "link_list.h"

char	*create_line(t_stacks *stacks, int max)
{
	char	*line;
	int		i;

	if ((line = ft_strnew(max)) != NULL)
	{
		i = -1;
		while (++i < max)
			line[i] = '-';
	}
	return (line);
}

void	visu(t_stacks *stacks, char *str, int max)
{
	t_node	*node_a;
	t_node	*node_b;
	int	i;

	node_a = stacks->a.head;
	node_b = stacks->b.head;
	i = -1;
	while (++i < stacks->a.len + stacks->b.len)
	{
		if (i < stacks->a.len)
			ft_printf("%-*.*s ", max, node_a->value, str);
		else
			ft_printf("%*s ", max, "");
		if (i < stacks->b.len)
			ft_printf("%.*s\n", node_b->value, str);
		else
			ft_putchar('\n');
		if (i < stacks->a.len)
			node_a = node_a->next;
		if (i < stacks->b.len)
			node_b = node_b->next;
	}
}
