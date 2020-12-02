/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:18:44 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/02 22:32:51 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

time_t	get_time(t_info *info)
{
	time_t	ans;

	ans = info->stat.st_mtimespec.tv_sec;
	return (ans);
}

void	ft_lstsort(t_list *lst, void (*f)(t_list *), int cnt)
{
	int				i;
	t_list			*head;
	time_t	tmp;
	time_t	next;

	while (cnt > 0)
	{
		head = lst;
		i = 0;
		while (cnt - i > 0)
		{
			tmp = get_time(head->content);
			next = get_time(head->next->content);
			if (tmp > next)
				f(head);
			i++;
		}
		cnt--;
	}
}

