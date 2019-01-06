/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 01:10:10 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 01:10:38 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"
#include "link_list.h"
#include "operations.h"

void	rev_rot(t_lst *lst, char c)
{
	if (lst && lst->len >= 2)
	{
		lst->head = lst->head->prev;
		lst->tail = lst->tail->prev;
		if (c == 'a' || c == 'b')
			ft_printf("rr%c\n", c);
	}
}

void	sswap(t_lst *a, t_lst *b, char *str)
{
	swap(a, 0);
	swap(b, 0);
	if (ft_strequ(str, "ss"))
		ft_printf("ss\n");
}

void	rrot(t_lst *a, t_lst *b, char *str)
{
	rot(a, 0);
	rot(b, 0);
	if (ft_strequ(str, "rr"))
		ft_printf("rr\n");
}

void	rrev_rot(t_lst *a, t_lst *b, char *str)
{
	rev_rot(a, 0);
	rev_rot(b, 0);
	if (ft_strequ(str, "rrr"))
		ft_printf("rrr\n");
}
