/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 16:18:58 by wta               #+#    #+#             */
/*   Updated: 2019/01/01 19:28:45 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "read.h"

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

int	read_args(int ac, char **av, t_inttab *inttab)
{
	int	idx;

	idx = 1;
	if (ac > 1)
	{
		if ((inttab->tab = ft_memalloc(sizeof(int) * (ac - 1))) != NULL)
		{
			while (idx < ac)
			{
				if (check_arg(av[idx], &inttab->tab[idx - 1]) == 0)
				{
					free(inttab->tab);
					return (0);
				}
				idx++;
			}
		}
	}
	return (idx - 1);
}
