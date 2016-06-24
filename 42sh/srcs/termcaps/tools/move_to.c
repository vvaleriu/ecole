/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 23:29:19 by vincent           #+#    #+#             */
/*   Updated: 2016/04/07 12:20:01 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>

/*
** Deplace le curseur a une position donnee
** sauvegarde cette position dans la structure de tconf pour garde le position
** actuelle du curseur en memoire
*/

void		move_to(int x, int y)
{
	char		*res;
	t_tconf		*conf;

	res = tgetstr("cm", NULL);
	tputs(tgoto(res, x, y), 1, putchar_int);
	conf = get_instance()->conf;
	CUR_X = x;
	CUR_Y = y;
}
