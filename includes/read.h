/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 16:45:48 by wta               #+#    #+#             */
/*   Updated: 2019/01/06 01:21:59 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include "link_list.h"

typedef struct	s_tab
{
	int	*tab;
	int	len;
}				t_tab;

int				read_args(int ac, char **av, t_lst *lst);

#endif
