/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 07:01:43 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/02 21:16:05 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

/*
** opendir(path)でDIRを取得
** 	->失敗したらperror
** readdir(DIR)でdirentを取得(各プロパティが格納)
** 	->d_name, d_namlen
** path = strcat(path, d_name)
** lstat(path, &stat)でstatを取得
** 	->st_mtimespec(変更日時)
** 名前と変更日時を線形リストに保存
** 変更日時によるsortをかける
** 名前を改行ありで出力
*/
/*
int	main(int ac, char **av)
{
	char			*path = "./";
	DIR				*dir;
	struct dirent	*dent;

	ft_putstr_fd("\033[31mHello ft_mini_ls\033[39m\n", 1);
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
		if (dent->d_name[0] != '.')
		{
			ft_putstr_fd(dent->d_name, 1);
			ft_putstr_fd("\n", 1);
		}
	}
	closedir(dir);
	return (0);
}
*/

int	main(int ac, char **av)
{
	t_list	*infolist;
	int		count;
	DIR		*dir;

	count = 0;
	if (ac > 1)
	{
		ft_putstr_fd(ft_strjoin(av[1], ": bad argument\n"), 2);
		return (1);
	}
	dir = opendir("./");
	/* t_listの形式にディレクトリ内のファイルt_infoを保存 */
	infolist = ft_readdir(dir, &count);
	/* t_info->stat.st_mtimespecを元古い順に並び替え */
	ft_lstsort(infolist, ft_lstswap, count);
	/* infolistをひたすら出力する */
	ft_lstiter(infolist, ft_print_dir);
	return (0);
}
