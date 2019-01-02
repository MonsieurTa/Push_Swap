/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/01 16:45:48 by wta               #+#    #+#             */
/*   Updated: 2019/01/01 16:49:45 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

typedef struct	s_inttab
{
	int	*tab;
	int	len;
}				t_inttab;

int	read_args(int ac, char **av, t_inttab *inttab);

#endif
