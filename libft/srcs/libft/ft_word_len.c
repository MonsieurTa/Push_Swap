/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:58:33 by wta               #+#    #+#             */
/*   Updated: 2018/08/09 16:51:57 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_len(char const *s, char c)
{
	char const	*ref;

	ref = NULL;
	if (s)
	{
		ref = s;
		while (*s != c && *s != 0)
			s++;
	}
	return (s - ref);
}
