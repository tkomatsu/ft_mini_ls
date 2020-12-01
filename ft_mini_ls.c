/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 07:01:43 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/02 08:21:42 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

int	main(int ac, char **av)
{
	char			*path = "./";
	DIR				*dir;
	struct dirent	*dent;

	if (ac > 1)
		path = av[1];
	dir = opendir(path);
	if (!dir)
	{
		perror(path);
		return (1);
	}
	while ((dent = readdir(dir)) != NULL)
	{
		ft_putstr_fd(dent->d_name, 1);
		ft_putstr_fd("\n", 1);
	}
	closedir(dir);
	return (0);
}
