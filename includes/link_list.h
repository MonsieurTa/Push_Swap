/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:02:52 by wta               #+#    #+#             */
/*   Updated: 2018/12/30 17:42:48 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINK_LIST_H
# define LINK_LIST_H

typedef struct	s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				value;
}				t_node;

typedef struct	s_lst
{
	t_node	*head;
	t_node	*tail;
	int		len;
}				t_lst;


t_node	*newnode(int value);
void	init_lst(t_lst *lst);
void	pushfront(t_lst *lst, t_node *node);
void	pushback(t_lst *lst, t_node *node);
t_node	*pop_front(t_lst *lst);
void	rm_lst(t_lst *lst);

#endif
