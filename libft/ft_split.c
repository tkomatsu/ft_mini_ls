/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 19:23:46 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/07/11 20:32:44 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		my_strcount(char const *s, char c)
{
	size_t	i;
	size_t	res;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			res++;
		i++;
	}
	return (res);
}

static size_t		my_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static unsigned int	my_nextstart(char const *s, char c, unsigned int i)
{
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static void			my_freeall(char **arr, size_t i)
{
	while (0 <= i)
	{
		free(*arr);
		i--;
	}
	free(arr);
}

char				**ft_split(char const *s, char c)
{
	char			**ans;
	unsigned int	start;
	size_t			i;

	if (!s)
		return (NULL);
	if (!(ans = ft_calloc(my_strcount(s, c) + 1, sizeof(char *))))
		return (NULL);
	start = my_nextstart(s, c, 0);
	i = 0;
	while (i < my_strcount(s, c))
	{
		if (!(ans[i] = ft_substr(s, start, my_strclen((s + start), c))))
		{
			my_freeall(ans, i);
			return (NULL);
		}
		start += (my_strclen((s + start), c));
		start = my_nextstart(s, c, start);
		i++;
	}
	return (ans);
}
