/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 10:11:03 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/28 12:59:44 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>
#include <libft.h>
#include <dirent.h>
#include <stdlib.h>


/*
** exe_path[0] = exec name
** exe_path[1] = word path sent to the shell
*/
static void		build_files_list(t_dlist **start, char *path, char *word)
{
	DIR					*dir;
	struct dirent		*fo;
	char				*str;

	if ((dir = opendir(path)))
	{
		while ((fo = readdir(dir)) != NULL)
		{
			if (word == NULL || (!ft_strncmp(fo->d_name, word, ft_strlen(word))))
			{
				str = (fo->d_type == DT_DIR ? ft_strjoin(fo->d_name, "/") : \
					ft_strdup(fo->d_name));
				ft_dlstadd(start, ft_dlstnew((void *)str, sizeof(char *)));
			}
		}
		closedir(dir);
	}
}

/*
** ret[0] = folder;
** ret[1] = file;
*/
void	get_word_and_folder(char *ret[], char *word)
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
		if (i == (int)ft_strlen(word))
		{
			ret[0] = ft_strdup("./");
			ret[1] = ft_strdup(word);
		}
		else
		{
			ret[0] = ft_strndup(word, (int)ft_strlen(word) - i);
			ret[1] = ft_strdup(word + i + 1);
		}
	}
}

t_dlist		*create_files_list(char *word)
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


