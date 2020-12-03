/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:18:14 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/03 18:39:13 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

void	ft_print_dir(void *arg)
{
	t_info *info;

	info = (t_info*)arg;
	ft_putstr_fd(info->name, 1);
	ft_putchar_fd('\n', 1);
	/*
	printf("%15s :%lu\n", info->name, info->stat.st_mtimespec.tv_sec);
	*/
}
