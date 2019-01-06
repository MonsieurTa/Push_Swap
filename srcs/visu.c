/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 05:58:14 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 10:29:25 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../libft/includes/libft.h"
#include "link_list.h"

char	*create_line(int max)
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
	int		i;

	node_a = stacks->a.head;
	node_b = stacks->b.head;
	i = -1;
	while (++i < stacks->a.len + stacks->b.len)
	{
		if (i < stacks->a.len && node_a->value >= 0)
			ft_printf("\e[0;32m%-*.*s\e[1;37m ", max, node_a->value, str);
		else if (i < stacks->a.len && node_a->value < 0)
			ft_printf("\e[0;31m%-*.*s\e[1;37m ", max,
					ft_abs(node_a->value), str);
		else
			ft_printf("%*s ", max, "");
		if (i < stacks->b.len && node_b->value >= 0)
			ft_printf("\e[0;32m%-*.*s\e[1;37m\n", max, node_b->value, str);
		else if (i < stacks->b.len && node_b->value < 0)
			ft_printf("\e[0;31m%.*s\e[1;37m\n", ft_abs(node_b->value), str);
		else
			ft_putchar('\n');
		node_a = (i < stacks->a.len) ? node_a->next : node_a;
		node_b = (i < stacks->b.len) ? node_b->next : node_b;
	}
}
