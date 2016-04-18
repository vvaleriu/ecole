/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 08:40:28 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/05 12:40:36 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

int		is_builtin(char *exe, t_var *var)
{
	int		i;

	i = 0;
	while (i < BIN_NB)
	{
		if (!ft_strcmp(exe, var->bin[i].na))
			return (1);
		i++;
	}
	return (0);
}
