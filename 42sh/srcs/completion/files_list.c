/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 10:11:03 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:27:01 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <libft.h>
#include <dirent.h>
#include <stdlib.h>

/*
** ret[0] = folder;
** ret[1] = file;
*/

static void		build_files_list(t_dlist **start, char *path, char *wd)
{
	DIR					*dir;
	struct dirent		*fo;
	char				*str;
	char				*tmp;

	if ((dir = opendir(path)))
	{
		while ((fo = readdir(dir)) != NULL)
		{
			if (wd == NULL || (!ft_strncmp(fo->d_name, wd, ft_strlen(wd))))
			{
				str = (fo->d_type == DT_DIR ? ft_strjoin(fo->d_name, "/") : \
					ft_strdup(fo->d_name));
				if (ft_strcmp(path, "./"))
				{
					tmp = str;
					str = ft_strjoin(path, str);
					ft_strdel(&tmp);
				}
				ft_dlstadd_last(start, ft_dlstnew((void *)str, sizeof(char *)));
			}
		}
		closedir(dir);
	}
}

static void		lolipopu(char *ret[], char *word, int i)
{
	if (i == (int)ft_strlen(word))
	{
		ret[0] = ft_strdup("./");
		ret[1] = ft_strdup(word);
	}
	else if (!i)
	{
		ret[0] = ft_strdup(word);
		ret[1] = 0;
	}
	else
	{
		ret[0] = ft_strndup(word, (int)ft_strlen(word) - i);
		ret[1] = ft_strdup(word + (int)ft_strlen(word) - i);
	}
}

/*
** ret[0] = folder;
** ret[1] = file;
*/

void			get_word_and_folder(char *ret[], char *word)
{
	int		i;

	i = 0;
	if (!word)
	{
		ret[0] = ft_strdup("./");
		ret[1] = NULL;
	}
	else
	{
		ft_strrev(word);
		while (word[i] && word[i] != '/')
			i++;
		ft_strrev(word);
		lolipopu(ret, word, i);
	}
}

t_dlist			*create_files_list(char *word)
{
	t_dlist		*start;
	char		*wd[2];

	start = NULL;
	get_word_and_folder(wd, word);
	build_files_list(&start, wd[0], wd[1]);
	if (wd[1])
		free(wd[1]);
	if (wd[0])
		free(wd[0]);
	return (start);
}
