/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:02:52 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 01:21:06 by wta              ###   ########.fr       */
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

typedef struct	s_stacks
{
	t_lst	a;
	t_lst	b;
	int		rrr_rot;
	int		rb_rot;
	int		a_rot;
	int		b_rot;
}				t_stacks;

t_node			*newnode(int value);
t_node			*pop_front(t_lst *lst);
void			init_lst(t_lst *lst);
void			pushfront(t_lst *lst, t_node *node);
void			pushback(t_lst *lst, t_node *node);
int				rm_lst(t_lst *lst);
void			init_stacks(t_stacks *stacks);

#endif
