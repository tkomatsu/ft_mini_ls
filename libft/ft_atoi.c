/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 22:24:54 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/07/05 09:14:51 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	result;
	long	sign;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign *= (str[i] == '-' ? (-1) : 1);
		i++;
	}
	if ('0' <= str[i] && str[i] <= '9')
	{
		while ('0' <= str[i] && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
			i++;
		}
	}
	result *= sign;
	return ((int)result);
}
