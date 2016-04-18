/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:14:06 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 11:35:31 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>
#include <libft.h>
#include <dirent.h>
#include <stdlib.h>

/*
** exe_path[0] = exec name
** exe_path[1] = exe path sent to the shell
*/

char			*ft_readdir(char *exe, char *rep)
{
	DIR					*dir;
	struct dirent		*fo;
	char				*tmp;
	char				*ret;

	ret = NULL;
	if ((dir = opendir(rep)))
	{
		while ((fo = readdir(dir)) != NULL)
			if (ft_strcmp(fo->d_name, exe) == 0)
			{
				ret = ft_strjoin(rep, "/");
				tmp = ret;
				ret = ft_strjoin(ret, fo->d_name);
				ft_strdel(&tmp);
				if (closedir(dir) == -1)
					ft_putendl("closedir() failed");
				return (ret);
			}
		if (closedir(dir) == -1)
			ft_putendl("closedir() failed");
	}
	return (ret);
}

/*
** rev l'exe entre puis cherche un '/'
** - si '/' alors la case 0 = executable
**					 case 1 = chemin entre
** - si pas de'/' alors la case 0 = executable
**					 case 1 = dossier actuel
** Va ajouter le repertoire courant de l'executale ainsi que le repertoire dans
** lequel on se trouve pour chercher dans les deux
** --------
** ligne 84 : inserer ret[0] = ft_strdup(exe);
*/

static char		**check_exe_name(char *exe)
{
	char	*tmp;
	int		i;
	char	**ret;

	i = 0;
	tmp = exe;
	ft_strrev(tmp);
	while (tmp[i] && tmp[i] != '/')
		i++;
	ret = (char **)ft_memalloc(sizeof(char *) * 3);
	if (tmp[i] != '\0')
	{
		ret[0] = ft_strndup(tmp, i);
		tmp += i;
		ret[1] = ft_strdup(tmp);
		ft_strrev(ret[1]);
	}
	else
	{
		ret[0] = ft_strdup(tmp);
		ret[1] = ft_strdup("./");
	}
	ft_strrev(ret[0]);
	return (ret);
}

void			add_path(char ***path, char **ad, char *current_pwd)
{
	ft_strarray_add_first(path, ad[0]);
	if (ad[1])
		ft_strarray_add_last(path, ad[1]);
	ft_strarray_add_last(path, current_pwd);
	free(ad[1]);
	free(ad[0]);
	free(ad);
}

char			*get_path(char *exe, char **env)
{
	int		i;
	char	**path;
	char	*ret;

	ret = NULL;
	path = NULL;
	i = 0;
	if (env)
	{
		while (ft_strncmp(env[i], "PATH=", 5))
			i++;
		path = ft_strsplit(env[i] + 5, ':');
	}
	i = 0;
	add_path(&path, check_exe_name(exe), get_env_value("PWD", env));
	while (++i && path[i])
		if ((ret = ft_readdir(path[0], path[i])) != NULL)
		{
			ft_strarray_del(&path);
			return (ret);
		}
	ft_putendl("command not found");
	ft_strarray_del(&path);
	return (NULL);
}
