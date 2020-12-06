/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 07:01:43 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/06 15:25:57 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

void	ft_delinfo(void *l)
{
	t_info	*info;

	info = (t_info*)l;
	free(info->name);
	free(l);
}

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
	char		*path;
	struct stat	dent_stat;

	list = NULL;
	while ((dent = readdir(dir)) != NULL)
	{
		if (dent->d_name[0] != '.')
		{
			info = ft_calloc(sizeof(t_info), 1);
			path = ft_strjoin("./", dent->d_name);
			if (!info || !path || lstat(path, &dent_stat))
				return (NULL);
			if (!(info->name = ft_strdup(dent->d_name)))
				return (NULL);
			info->namlen = dent->d_namlen;
			info->stat = dent_stat;
			free(path);
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
	ft_lstclear(&infolist, ft_delinfo);
	closedir(dir);
	return (0);
}
