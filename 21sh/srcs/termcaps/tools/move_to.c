/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 23:29:19 by vincent           #+#    #+#             */
/*   Updated: 2016/03/10 23:07:47 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** Deplace le curseur a une position donnee
** sauvegarde cette position dans la structure de tconf pour garde le position
** actuelle du curseur en memoire
*/
void 		move_to(int x, int y)
{
	char		*res;
	t_tconf		*conf;
 
	res = tgetstr("cm", NULL);
	tputs(tgoto(res, x, y), 1, putchar_int);
	conf = get_instance()->conf;
	CUR_X = x;
	CUR_Y = y;
}