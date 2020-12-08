/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 07:01:43 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/08 21:02:21 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

void	ft_print_dir(void *arg)
{
	t_info *info;

	info = (t_info*)arg;
	ft_putendl_fd(info->name, 1);
}

t_list	*ft_readdir(DIR *dir)
{
	t_list			*list;
	struct dirent	*dent;
	t_info			*info;
	struct stat		dent_stat;

	list = NULL;
	while ((dent = readdir(dir)))
	{
		if (*(dent->d_name) != '.')
		{
			info = malloc(sizeof(t_info));
			if (!info || lstat(dent->d_name, &dent_stat))
				return (NULL);
			ft_strlcpy(info->name, dent->d_name, __DARWIN_MAXPATHLEN);
			info->stat = dent_stat;
			ft_lstadd_back(&list, ft_lstnew(info));
		}
	}
	return (list);
}

int		cmp_time(void *va, void *vb)
{
	t_info	*a;
	t_info	*b;

	a = (t_info*)va;
	b = (t_info*)vb;
	if (a->stat.st_mtimespec.tv_sec > b->stat.st_mtimespec.tv_sec)
		return (1);
	else if (a->stat.st_mtimespec.tv_sec == b->stat.st_mtimespec.tv_sec)
	{
		if (a->stat.st_mtimespec.tv_nsec > b->stat.st_mtimespec.tv_nsec)
			return (1);
		else if (a->stat.st_mtimespec.tv_nsec == b->stat.st_mtimespec.tv_nsec)
		{
			if (ft_strcmp(a->name, b->name) < 0)
				return (1);
		}
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_list	*infolist;
	DIR		*dir;

	if (ac > 1)
		return (ft_puterr(av[0], 22));
	if (!(dir = opendir("./")))
		return (ft_puterr("./", 13));
	infolist = ft_readdir(dir);
	ft_lstsort(&infolist, cmp_time);
	ft_lstiter(infolist, ft_print_dir);
	ft_lstclear(&infolist, free);
	closedir(dir);
	return (EXIT_SUCCESS);
}
