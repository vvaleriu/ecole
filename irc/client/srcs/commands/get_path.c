/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:14:06 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/03/06 14:30:49 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <irc_client.h>
#include <dirent.h>

/*
** exe_path[0] = exec name
** exe_path[1] = exe path sent to the shell
*/

char		*ft_readdir(char *exe, char *rep)
{
	DIR					*dir;
	struct dirent		*fo;
	char				*tmp;
	char				*ret;

	ret = NULL;
	if ((dir = opendir(rep)))
	{
		while ((fo = readdir(dir)) != NULL)
		{
			if (ft_strcmp(fo->d_name, exe) == 0)
			{
				ret = ft_strjoin(rep, "/");
				tmp = ret;
				ret = ft_strjoin(ret, fo->d_name);
				ft_strdel(&tmp);
				if (closedir(dir) == -1)
					printf("closedir() failed");
				return (ret);
			}
		}
		if (closedir(dir) == -1)
			printf("closedir() failed");
	}
	return (ret);
}

/*
** cmda[0] est le nomde le'executable entre. Comme il s'agit d'une commande
** client, toutes les commandes prennent un c devant (ex : cls, cmkdir), on 
** cherche donc dans le path a partir de cmda[0] + 1 (donc : ls, mkdir)
*/

char		*get_path(t_cl_prop *cl, char **cmda)
{
	int		i;
	char	*ret;

	ret = NULL;
	i = 0;
	while (cl->path[++i])
		if ((ret = ft_readdir(cmda[0] + 1, cl->path[i])) != NULL)
			return (ret);
	ft_putendl("command not found");
	return (NULL);
}
