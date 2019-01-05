/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:32:15 by wta               #+#    #+#             */
/*   Updated: 2019/01/04 22:28:35 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

void	swap(t_lst *lst, char c);
void	sswap(t_lst *a, t_lst *b, char *str);
void	push_lst(t_lst *l1, t_lst *l2, char *str, char c);
void	rot(t_lst *lst, char c);
void	rev_rot(t_lst *lst, char c);
void	rrot(t_lst *a, t_lst *b,char *str);
void	rrev_rot(t_lst *a, t_lst *b,char *str);

#endif
