/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:00:49 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 01:07:22 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "link_list.h"
# include "read.h"

long long	ft_atoi_ll(char *str);
void		bubble_sort(t_lst *lst);
void		insertion_sort(t_lst *lst, t_lst *stack, t_tab *tab);
void		selection_sort(t_stacks *stacks);
void		move_in_lst(t_lst *lst, int lst_pos, int tab_pos);
void		print_list(t_lst *lst, char c);
void		ft_delsplit(char **split);
void		small_sort(t_lst *b, char c);
int			add_to_stack(t_lst *a, char **split);
int			do_op(t_stacks *stacks);
int			is_sort(t_lst *b);
int			is_num(char *str);
int			is_sort_from_h(t_lst *b);
int			get_max(t_lst *b);
int			d_from_max(t_lst *b, int value);
void		move_stacks(t_lst *a, t_lst *b, int len, char c);
int			best_b_rot(t_lst *b, int value);
int			fit_in_b(int value_a, t_node *node_b);
int			best_a_rot(t_lst *a, t_lst *b, int value);
int			opti_rot(t_lst *stack, int rot);
void		set_opti_rot(t_stacks *stacks, char *str, int i, int j);

#endif
