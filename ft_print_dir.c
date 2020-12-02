/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:18:14 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/02 22:38:11 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

void	ft_print_dir(void *finfo)
{
	t_info *tmp;

	tmp = (t_info*)finfo;
	ft_putstr_fd(tmp->name, 1);
	ft_putchar_fd('\n', 1);
}
