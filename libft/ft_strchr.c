/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 22:09:37 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/06/30 09:20:28 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ch;

	ch = (char*)s;
	i = 0;
	while (ch[i] != 0 && ch[i] != (char)c)
		i++;
	if (ch[i] == (char)c)
		return (ch + i);
	return (NULL);
}
