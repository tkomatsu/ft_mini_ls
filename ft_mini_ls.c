/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 07:01:43 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/03 12:21:32 by tkomatsu         ###   ########.fr       */
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
	/* t_listの形式にディレクトリ内のファイルt_infoを保存 */
	infolist = ft_readdir(dir);
	puts("\033[34mBEFORE\033[39m");
	ft_lstiter(infolist, ft_print_dir);
	/* t_info->stat.st_mtimespecを元古い順に並び替え */
	ft_lstsort(infolist);
	/* infolistをひたすら出力する */
	puts("\033[34mAFTER\033[39m");
	ft_lstiter(infolist, ft_print_dir);

	/*
	printf("*******cmp_time test*****\n");
	ft_print_dir(infolist->content);
	ft_print_dir(infolist->next->content);
	printf("cmp_time: %d\n", cmp_time(infolist->content, infolist->next->content));
	*/

	return (0);
}
