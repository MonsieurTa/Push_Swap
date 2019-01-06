/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 00:58:41 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 01:20:16 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "link_list.h"

void		init_lst(t_lst *lst)
{
	if (lst != NULL)
	{
		lst->head = NULL;
		lst->tail = NULL;
		lst->len = 0;
	}
}

void		print_list(t_lst *lst, char c)
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

void		ft_delsplit(char **split)
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

int			is_num(char *str)
{
	int	idx;

	if (str)
	{
		idx = (str[0] == '-' || str[0] == '+') ? 1 : 0;
		if (str[idx] == '\0')
			return (0);
		while (str[idx] >= '0' && str[idx] <= '9')
			idx++;
		if (str[idx] == '\0')
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
