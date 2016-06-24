/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:03:49 by vincent           #+#    #+#             */
/*   Updated: 2016/04/07 12:07:07 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>

int		move_to_next_line(t_var *var)
{
	var = (void *)var;
	set_str_cap("do");
	return (2);
}

/*
** Fonction executee lors d'un appui sur home
*/

int		move_to_origin(t_var *var)
{
	int		i;

	i = LN_POS;
	while (--i >= 0)
		move_to_previous_char(var);
	return (2);
}

/*
** Fonction executee lors d'un appui sur end
*/

int		move_to_end(t_var *var)
{
	while (var->line.pos < (int)ft_strlen(var->line.s))
		move_to_next_char(var);
	return (2);
}
