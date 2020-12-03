/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 21:13:17 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/07/10 21:35:39 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*result;
	int		i;
	int		len;

	len = ft_strlen(src);
	i = 0;
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	while (src[i])
	{
		result[i] = src[i];
		i++;
	}
	result[i] = 0;
	return (result);
}
