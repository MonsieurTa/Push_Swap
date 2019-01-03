/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:32:15 by wta               #+#    #+#             */
/*   Updated: 2019/01/03 02:19:30 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

void	swap(t_lst *lst);
void	push_lst(t_lst *l1, t_lst *l2, char *str);
void	rotate(t_lst *lst);
void	reverse_rotate(t_lst *lst);

#endif
