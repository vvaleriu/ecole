/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:23:20 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/03/03 15:30:14 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_minishell2.h>

void		clean_env(t_var *var)
{
	int		i;

	i = 0;
	if (var->tenv)
	{
		while (var->tenv[i])
		{
			free(var->tenv[i]);
			i++;
		}
		free(var->tenv);
		var->tenv = NULL;
	}
}
