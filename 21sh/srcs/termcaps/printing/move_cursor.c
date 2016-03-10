/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:03:49 by vincent           #+#    #+#             */
/*   Updated: 2016/03/10 18:25:10 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** Delace le curseur sur la prochaine/precedente case. Calcule le retour a la
** ligne si necessaire
*/
int		move_to_next_char(t_var *var)
{
	t_tconf		*conf;

	conf = var->conf;
	(void)conf;
	/*if (CUR_X == WIN_X)
		move_to(0, CUR_Y + 1);
	else
		move_to(CUR_X + 1, CUR_Y);*/
	set_str_cap("nd");
	return (2);
}

int		move_to_previous_char(t_var *var)
{
	t_tconf		*conf;

	conf = var->conf;
	(void)conf;
	/*if (CUR_X == 0)
		move_to(WIN_X, CUR_Y - 1);
	else
		move_to(CUR_X - 1, CUR_Y);*/
	set_str_cap("le");
	return (2);
}

int		move_cursor(t_var *var)
{
	t_tconf		*conf;
	
	conf = var->conf;
	(void)conf;
	move_to(0, 0);
	return (2);
}