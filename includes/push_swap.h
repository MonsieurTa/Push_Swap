/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:00:49 by wta               #+#    #+#             */
/*   Updated: 2019/01/01 18:30:23 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_lst_info
{
	int	sorted_h;
	int	sorted_t;
}				t_lst_info;



void	bubble_sort(t_lst *lst);
int		is_sort(t_lst *lst, t_lst_info *info);
void	quicksort_tab(int *tab, int start, int end);

#endif
