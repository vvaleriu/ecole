/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 08:40:40 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/10 12:05:32 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

t_var		*get_instance()
{
	static t_var	*var;

	if (var == NULL)
	{
		var = (t_var *)ft_memalloc(sizeof(*var));
	}
	return (var);
}

t_tconf		*get_conf()
{
	return (get_instance()->conf);
}