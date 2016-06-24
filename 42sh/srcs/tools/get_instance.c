/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 08:40:40 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:14:26 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>

t_var		*get_instance(void)
{
	static t_var	*var = NULL;

	if (var == NULL)
		var = (t_var *)ft_memalloc(sizeof(*var));
	return (var);
}

t_tconf		*get_conf(void)
{
	return (get_instance()->conf);
}
