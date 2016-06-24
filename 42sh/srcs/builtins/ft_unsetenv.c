/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:22:59 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/19 09:47:42 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <ft_42sh.h>

/*
** Look for an already set variable with the same name
** If not set, set the new var
** If set already, check if it needs to be overwrtitten or not and apply the
** appropriate action
** PATH env can't be overwritten
*/

int			ft_unsetenv(char **exe, void *var1)
{
	int		t[3];
	t_var	*v;

	K = 0;
	J = 0;
	v = (t_var *)var1;
	if ((exe[1] && ft_strcmp(exe[1], "PATH")))
	{
		if ((I = find_env(exe[1], v->tenv)) != -1)
			ft_strcarray_del_one(&(v->tenv), I);
	}
	else
		ft_printf("usage : unsetenv VAR.\n");
	return (0);
}
