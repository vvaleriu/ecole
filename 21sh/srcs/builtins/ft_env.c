/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:33:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/27 10:09:34 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_minishell2.h>

int			ft_env(char **exe, void *var)
{
	int		i;
	t_var	*v;

	i = 0;
	(void)exe;
	v = (t_var *)var;
	while (v->tenv[i] && *(v->tenv[i]) != '\0')
	{
		ft_putendl(v->tenv[i]);
		i++;
	}
	return (0);
}
