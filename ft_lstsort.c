/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:18:44 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/03 18:54:32 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

int		cmp_time(t_info *a, t_info *b)
{
	if (a->stat.st_mtimespec.tv_sec >= b->stat.st_mtimespec.tv_sec)
		return (1);
	return (0);
}

t_list	*ft_merge(t_list *a, t_list *b)
{
	t_list	result;
	t_list	*x;

	x = &result;
	while (a != NULL && b != NULL)
	{
		if (cmp_time(a->content, b->content) > 0)
		{
			x->next = b;
			x = x->next;
			b = b->next;
		}
		else
		{
			x->next = a;
			x = x->next;
			a = a->next;
		}
	}
	if (a == NULL)
		x->next = b;
	else
		x->next = a;
	return (result.next);
}

t_list	*ft_mergesort(t_list *lst)
{
	t_list	*a;
	t_list	*b;
	t_list	*x;

	if (!lst || !lst->next)
		return (lst);
	a = lst;
	b = lst->next;
	if (b != NULL)
		b = b->next;
	while (b != NULL)
	{
		a = a->next;
		b = b->next;
		if (b != NULL)
			b = b->next;
	}
	x = a->next;
	a->next = NULL;
	return (ft_merge(ft_mergesort(lst), ft_mergesort(x)));
}

void	ft_lstsort(t_list **lst)
{
	t_list	*result;

	if (!lst || !*lst)
		return ;
	result = ft_mergesort(*lst);
	*lst = result;
}
