/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 07:45:09 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/08 21:02:25 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <stdio.h>
# include "libft.h"
# include <stdbool.h>

typedef struct	s_info
{
	char		name[__DARWIN_MAXPATHLEN];
	struct stat stat;
}				t_info;

t_list			*ft_readdir(DIR *dir);
void			ft_print_dir(void *finfo);

#endif
