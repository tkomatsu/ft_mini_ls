/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:18:44 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/03 17:51:05 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

/*
** aが大きい時は1, bが大きい時は-1を返す
*/

int	cmp_time(t_info *a, t_info *b) {
	if (a->stat.st_mtimespec.tv_sec >= b->stat.st_mtimespec.tv_sec)
		return (1);
	return (0);
}

/*
**	x->next:回答、a:前半、b:後半
**	xの最初のノードは捨てる
*/

t_list	*ft_merge(t_list *a, t_list *b)
{
	t_list	*result;
	t_list	*x;

	puts("\033[31mft_merge\033[39m");
	puts("a *******");
	ft_lstiter(a, ft_print_dir);
	puts("b *******");
	ft_lstiter(b, ft_print_dir);
	x = ft_calloc(sizeof(t_list), 1);
	result = x;
	while (a != NULL && b != NULL)
	{
		if (cmp_time(a->content, b->content) > 0)
		{
			x->next = b;
			x = x->next; // xを進める
			b = b->next; // bを進める
		}
		else
		{
			x->next = a;
			x = x->next; // xを進める
			a = a->next; // aを進める
		}
	}
	if (a == NULL)
		x->next = b;
	else
		x->next = a;
	puts("x *******");
	ft_lstiter(result->next, ft_print_dir);
	return (result->next);
}

t_list	*ft_mergesort(t_list *lst)
{
	t_list	*a;
	t_list	*b;
	t_list	*x;

	/*
	puts("\033[31mft_mergesort\033[39m");
	ft_lstiter(lst, ft_print_dir);
	*/
	if (!lst || !lst->next)
		return lst;
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
	x = a->next; // bに中間地点の次のnodeをいれる
	a->next = NULL;
	/*
	puts("\033[32mlst\033[39m");
	ft_lstiter(lst, ft_print_dir);
	puts("\033[32mx\033[39m");
	ft_lstiter(x, ft_print_dir);
	*/
	return (ft_merge(ft_mergesort(lst), ft_mergesort(x))); //lstは先頭、bは中央の次のnode
}

void	ft_lstsort(t_list *lst)
{
	t_list	*result;

	if (!lst)
		return;
	result = ft_mergesort(lst->next);
	lst->next = result;
}

