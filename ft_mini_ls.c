/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 07:01:43 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/04 21:40:19 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

int	main(int ac, char **av)
{
	t_list	*infolist;
	DIR		*dir;

	if (ac > 1)
	{
		ft_putstr_fd(ft_strjoin(av[1], ": bad argument\n"), 2);
		return (1);
	}
	dir = opendir("./");
	infolist = ft_readdir(dir);
	ft_lstsort(&infolist);
	ft_lstiter(infolist, ft_print_dir);
	ft_lstclear(&infolist, ft_delinfo);
	closedir(dir);
	return (0);
}
