/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 21:16:36 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/02 21:57:04 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

static t_info	*read_finfo(struct dirent *dent)
{
	t_info		*info;
	char		*path;
	struct stat	dent_stat;

	info = ft_calloc(sizeof(t_info), 1);
	path = ft_strjoin("./", dent->d_name);
	if (!info || !path || lstat(path, &dent_stat))
		return (NULL);
	info->name = ft_strdup(dent->d_name);
	info->namlen = dent->dnumlen;
	info->stat = dent_stat;
	return (info);
}

t_list	*ft_readdir(DIR *dir, int *count)
{
	t_list			*infolist;
	char			*path;
	struct dirent	*dent;
	t_info			*finfo;

	infolist = NULL;
	while (dent = readdir(dir))
	{
		if (dent->d_name[0] != '.')
		{
			*count++;
			finfo = read_finfo(dent);
			if (!infolist)
				infolist = ft_lstnew(finfo);
			else
				ft_lstadd_back(infolist, ft_lstnew(finfo));
		}
	}
	return (infolist);
}
