/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 16:18:58 by wta               #+#    #+#             */
/*   Updated: 2019/01/05 22:42:15 by wta              ###   ########.fr       */
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
	int		ret;

	idx = 1;
	ret = 1;
	if (ac > 1)
	{
		while (ret == 1 && idx < ac)
		{
			if ((split = ft_strsplit(av[idx], ' ')) != NULL
			&& add_to_stack(lst, split) == 0)
				ret = 0;
			else if (split == NULL)
				ret = 0;
			idx++;
		}
		if (ret == 0)
		{
			ft_putstr_fd("Error\n", 2);
			rm_lst(lst);
		}
	}
	return (ret);
}
