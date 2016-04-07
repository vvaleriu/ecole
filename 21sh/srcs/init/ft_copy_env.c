/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 17:09:40 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 06:49:17 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_minishell2.h>

int			ft_copy_env(t_var *var, char **env)
{
	int i;

	i = 0;
	if (env && ft_strarray_len(env))
	{
		while (env[i])
			i++;
		var->tenv = (char **)ft_memalloc(sizeof(char *) * (i + 1));
		while (--i >= 0)
			var->tenv[i] = ft_strdup(env[i]);
		return (0);
	}
	return (-1);
}
