/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:15:13 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/07/05 20:41:51 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lstnow;
	t_list	*lstnext;

	lstnow = *lst;
	while (lstnow)
	{
		lstnext = lstnow->next;
		ft_lstdelone(lstnow, del);
		lstnow = lstnext;
	}
	*lst = NULL;
}
