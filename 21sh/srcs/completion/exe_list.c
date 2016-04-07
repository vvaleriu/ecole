/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 10:10:51 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 08:02:35 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>
#include <libft.h>
#include <dirent.h>
#include <stdlib.h>

static char		**get_path_from_env(t_var *var)
{
	int		i;
	char	**path;

	path = NULL;
	i = 0;
	if (var->tenv)
	{
		while (ft_strncmp(var->tenv[i], "PATH=", 5))
			i++;
		path = ft_strsplit(var->tenv[i] + 5, ':');
	}
	return (path);
}

/*
** exe_path[0] = exec name
** exe_path[1] = word path sent to the shell
*/
static t_dlist	*build_exe_list(char **path, char *word)
{
	DIR					*dir;
	struct dirent		*fo;
	int					i;
	t_dlist				*start;

	i = 0;
	start = NULL;
	while (path[i])
	{
		if ((dir = opendir(path[i])))
		{
			while ((fo = readdir(dir)) != NULL)
			{
				if (!ft_strncmp(fo->d_name, word, ft_strlen(word)))
					ft_dlstadd_last(&start, ft_dlstnew((void *)\
						ft_strdup(fo->d_name), sizeof(char *)));
			}
			closedir(dir);
		}
		i++;
	}
	return (start);
}

void		delete_completion_list(void *content, size_t size)
{
	if (size)
	{
		free(content);
		content = NULL;
	}
}

t_dlist		*create_exe_list(t_var *var, char *word)
{
	t_dlist		*start;
	char		**path;

	start = NULL;
	if (word)
	{
		path = get_path_from_env(var);
		start = build_exe_list(path, word);
		ft_strarray_del(&path);
	}
	return (start);
}


