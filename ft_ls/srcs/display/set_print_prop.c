/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_print_prop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 17:01:28 by vincent           #+#    #+#             */
/*   Updated: 2015/08/08 19:25:57 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** compares the size of each column to store the widest of each to then setup
** the right column size when displaying.
*/

void		set_print_prop(t_file *file, short *pp)
{
	int		a;

	CB_L = (file->type == 'c' ? 1 : CB_L);
	CB_L = (file->type =='b' ? 1 : CB_L);
	LK_L = ((a = LEN(file->link_nb)) > LK_L ? a : LK_L);
	USR_L = ((a = LEN(file->user)) > USR_L ? a : USR_L);
	GRP_L = ((a = LEN(file->group)) > GRP_L ? a : GRP_L);
	SIZE_L = ((a = LEN(file->size)) > SIZE_L ? a : SIZE_L);
	MOD_L = ((a = LEN(file->mod)) > MOD_L ? a : MOD_L);
	MIN_L = ((a = LEN(file->min)) > MIN_L ? a : MIN_L);
	MAN_L = ((a = LEN(file->man)) > MAN_L ? a : MAN_L);
	BLK_L = BLK_L + file->blk;
}
