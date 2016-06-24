/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 14:23:20 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:28:46 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_42sh.h>

/*
** void		clean_env(t_var *var)
** {
** 	int		i;
**  --
** 	i = 0;
** 	if (var->tenv)
** 	{
** 		while (var->tenv[i])
** 		{
** 			free(var->tenv[i]);
** 			i++;
** 		}
** 		free(var->tenv);
** 		var->tenv = NULL;
** 	}
** }
*/

void		clean_env(t_var *var)
{
	int		i;

	i = -1;
	if (var->tenv)
	{
		while (++i && var->tenv[i])
			ft_strdel(&(var->tenv[i]));
		free(var->tenv);
		var->tenv = NULL;
	}
}
