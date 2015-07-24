/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 12:01:43 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/03/06 15:33:04 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <unistd.h>
#include <ft_minishell2.h>

void		ft_mod_pwd(char **env)
{
	char	path[1000];
	int		i;
	int		j;
	char	*del;

	i = ft_find_env("PWD", env);
	del = ((j = ft_find_env("OLDPWD", env)) != -1 ? env[j] : NULL);
	if (del)
		free(del);
	if (j != -1)
		env[j] = ft_strjoin("OLDPWD=", env[i] + 4);
	else
	{
		ft_strarray_add_first(&env, (del = ft_strjoin("OLDPWD=", env[i] + 4)));
		ft_strdel(&del);
	}
	del = env[i];
	free(del);
	env[i] = ft_strjoin("PWD=", getcwd(path, 1000));
}

int			ft_find_env(char *exe, char **env)
{
	int		i;
	int		j;
	char	*cmp;

	i = 0;
	j = 0;
	while (env[i])
	{
		while (env[i][j] && env[i][j] != '=')
			j++;
		cmp = ft_strndup(env[i], j);
		if (!ft_strcmp(cmp, exe))
		{
			ft_strdel(&cmp);
			return (i);
		}
		ft_strdel(&cmp);
		i++;
		j = 0;
	}
	return (-1);
}

void		ft_cd(char **exe, void *var)
{
	int		ret;
	char	*path;
	t_var	*var1;

	path = NULL;
	var1 = (t_var *)var;
	if (!exe[1] || (exe[1] && !ft_strncmp(exe[1], "~", 1)))
	{
		path = ft_strdup(var1->tenv[ft_find_env("HOME", var1->tenv)] + 5);
		ret = chdir(path);
	}
	else if (!ft_strcmp(exe[1], "-"))
		ret = chdir(var1->tenv[ft_find_env("OLDPWD", var1->tenv)] + 7);
	else
		ret = chdir(exe[1]);
	if (ret == -1)
		ft_putendl("Could not access directory");
	else
		ft_mod_pwd(var1->tenv);
	ft_strdel(&path);
}
