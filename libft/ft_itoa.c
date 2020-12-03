/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:03:58 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/07/03 10:01:53 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_numlen(long num)
{
	size_t	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num != 0)
	{
		if (num < 0)
		{
			len++;
			num *= (-1);
		}
		len++;
		num /= 10;
	}
	return (len);
}

static void		my_itoa(char *s, long num, int *i)
{
	if (num < 0)
	{
		s[*i] = '-';
		*i += 1;
		my_itoa(s, num * (-1), i);
	}
	else if (0 <= num && num <= 9)
	{
		s[*i] = num + '0';
	}
	else
	{
		my_itoa(s, num / 10, i);
		*i += 1;
		s[*i] = num % 10 + '0';
	}
}

char			*ft_itoa(int n)
{
	char	*res;
	long	num;
	size_t	numlen;
	int		i;

	num = (long)n;
	numlen = my_numlen(num);
	if ((res = ft_calloc(numlen + 1, sizeof(char))) == NULL)
		return (NULL);
	i = 0;
	if (num == 0)
		res[0] = '0';
	else
		my_itoa(res, num, &i);
	return (res);
}
