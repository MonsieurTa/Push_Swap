/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:00:49 by wta               #+#    #+#             */
/*   Updated: 2019/01/05 17:48:39 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "link_list.h"
# include "read.h"

void	bubble_sort(t_lst *lst);
void	insertion_sort(t_lst *lst, t_lst *stack, t_tab *tab);
void	selection_sort(t_stacks *stacks);
void	move_in_lst(t_lst *lst, int lst_pos, int tab_pos);
void	print_list(t_lst *lst, char c);
int	add_to_stack(t_lst *a, char **split);
void	ft_delsplit(char **split);

#endif
