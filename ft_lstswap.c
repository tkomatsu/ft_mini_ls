/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:18:32 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/02 22:05:29 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

void	ft_lstswap(t_list *lst)
{
	void	*tmp;

	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
}
