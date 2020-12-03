/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:22:40 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/07/09 20:23:11 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	k;

	if (s == NULL || ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(res = (char*)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] && k < len)
	{
		if (i >= start)
		{
			res[k] = s[i];
			k++;
		}
		i++;
	}
	return (res);
}
