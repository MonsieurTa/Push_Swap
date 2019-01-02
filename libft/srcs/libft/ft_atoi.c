/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <wta@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 17:38:39 by wta               #+#    #+#             */
/*   Updated: 2019/01/01 17:09:14 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long		sign;
	long		res;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
			|| *str == '\t' || *str == '\v')
		str++;
	sign = (*str == '-') ? -1 : 1;
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (int)(*str++ - '0');
	res *= sign;
	if (sign == -1 && res > 0)
		return (-1);
	if (sign == 1 && res < 0)
		return (-1);
	return (res);
}
