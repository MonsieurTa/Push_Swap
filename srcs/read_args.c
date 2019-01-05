/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 16:18:58 by wta               #+#    #+#             */
/*   Updated: 2019/01/04 23:18:28 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "read.h"
#include "push_swap.h"

int	check_arg(char *str, int *value)
{
	char	*check;
	char	*needle;
	int		ret;
	int		nb;

	ret = 0;
	nb = ft_atoi(str);
	if ((check = ft_itoa(nb)) != NULL)
	{
		needle = str;
		if (*needle == '-')
			needle++;
		while (*(needle + 1) != '\0' && *needle == '0')
			needle++;
		ret = ft_strequ(needle, &check[(check[0] == '-')]);
		ft_strdel(&check);
		*value = nb;
	}
	return (ret);
}

int	build_lst(t_lst *lst, int value)
{
	t_node	*node;

	if ((node = newnode(value)) != NULL)
		pushback(lst, node);
	return (node != NULL);
}

int	read_args(int ac, char **av, t_lst *lst)
{
	char	**split;
	int		idx;

	idx = 1;
	if (ac > 1)
	{
		while (idx < ac)
		{
			if ((split = ft_strsplit(av[idx], ' ')) != NULL
			&& add_to_stack(lst, split) == 0)
				return (0);
			else if (split == NULL)
				return (rm_lst(lst));
			idx++;
		}
	}
	return (idx - 1);
}
