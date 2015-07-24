/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:22:59 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/03/05 16:31:05 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <ft_minishell2.h>

/*
** Look for an already set variable with the same name
** If not set, set the new var
** If set already, check if it needs to be overwrtitten or not and apply the
** appropriate action
*/

void			ft_unsetenv(char **exe, void *var1)
{
	int		t[3];
	t_var	*v;

	K = 0;
	J = 0;
	v = (t_var *)var1;
	if ((exe[1] && ft_strcmp(exe[1], "PATH")))
	{
		if ((I = find_env(exe[1], v->tenv)) != -1)
		{
			ft_printf("Numero de varenv trouve : %d\n", I);
			ft_printf("Valeur de varenv trouve : %s\n", v->tenv[I]);
			ft_strarray_del_one(&(v->tenv), I);
		}
	}
}
