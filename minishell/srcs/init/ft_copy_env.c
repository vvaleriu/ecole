/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 17:09:40 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/03/05 11:28:00 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_minishell2.h>

void		ft_copy_env(t_var *var, char **env)
{
	int i;

	i = 0;
	if (env)
	{
		while (env[i])
			i++;
		var->tenv = (char **)ft_memalloc(sizeof(char *) * (i + 1));
		while (--i >= 0)
			var->tenv[i] = ft_strdup(env[i]);
	}
}
