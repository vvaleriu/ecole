/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 13:15:59 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/05 12:40:59 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <42sh.h>

/*
** Look for an already set variable withe the same name
** If not set, set the new var
** If set already, check if it needs to be overwritten or not and apply the
** appropriate action
*/

static void		ft_add_env(char **exe, t_var *var, int i)
{
	int		j;

	j = 0;
	while (exe[i][j] && exe[i][j] != '=')
		j++;
	if (exe[i][j] == '=')
		ft_strarray_add_last(&(var->tenv), exe[i]);
}

static void		ft_modify_env(char **exe, t_var *var, int i, int n)
{
	ft_strarray_del_one(&(var->tenv), n);
	ft_strarray_add_last(&(var->tenv), exe[i]);
}

static int		check_already_env(char *newenv, t_var *var)
{
	char	*check;
	char	**split;
	int		ret;

	check = newenv;
	while (*check && *check != '=')
		check++;
	if (*check)
	{
		split = ft_strsplit(newenv, '=');
		ret = find_env(split[0], var->tenv);
		ft_strarray_del(&split);
		return (ret);
	}
	return (-1);
}

int				ft_setenv(char **exe, void *var)
{
	int		j;
	int		n;
	t_var	*var1;

	var1 = (t_var *)var;
	j = 1;
	if (!exe[1])
		ft_putendl("usage : setenv VAR=VALUE");
	else
	{
		while (exe[j])
		{
			if ((n = check_already_env(exe[j], var1)) == -1)
				ft_add_env(exe, var1, j);
			else
				ft_modify_env(exe, var1, j, n);
			j++;
		}
	}
	return (0);
}
