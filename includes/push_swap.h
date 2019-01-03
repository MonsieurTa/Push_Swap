/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:00:49 by wta               #+#    #+#             */
/*   Updated: 2019/01/02 23:42:08 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "link_list.h"
# include "read.h"

void	bubble_sort(t_lst *lst);
void	quicksort_tab(int *tab, int start, int end);
void	insertion_sort(t_lst *lst, t_lst *stack, t_tab *tab);
void	move_in_lst(t_lst *lst, int lst_pos, int tab_pos);
void	print_list(t_lst *lst);

#endif
