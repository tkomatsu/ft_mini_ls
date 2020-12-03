/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 20:54:31 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/04 07:53:34 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	int		i;
	int		k;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	ans = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		ans[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k] != 0)
		ans[i++] = s2[k++];
	ans[i] = 0;
	return (ans);
}
