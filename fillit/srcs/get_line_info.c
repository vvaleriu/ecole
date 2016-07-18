/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 23:50:39 by vincent           #+#    #+#             */
/*   Updated: 2016/07/15 17:50:03 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Verifie qu'il n'y a pas de probleme horizontal sur le bit de droite recu
** en parametre
*/
static int 				hz_check(unsigned short piece_bit)
{
	unsigned short test;

	test = piece_bit & 0x000F;
	if (test == 5 || test == 9 || test == 10)
		return (0);
	return (1);
}

/*
** Verifie que les pieces se touchent bien ensembles.
** On parcours chaque bloc de la piece et on verifie qu'il touche bien un autre
** bloc
** bit_nb: numero du bit que l'on est en train de verifier (on commence en haut
** a gauche, donc au 16ieme bit en realite)
*/
static int					check_contiguous(unsigned short piece)
{
	unsigned short	i;
	unsigned short	total;
	unsigned short	prev;

	i = -1;
	total = 0;
	while (++i < 3)
	{
		prev = (piece >> (4 * i)) & 0x000F;
		total += (prev & 1) + ((prev >> 1) & 1) + ((prev >> 2) & 1) + ((prev >> 3) & 1);
		if (total == 4)
			return (1);
		if (!hz_check(prev))
			return (0);
		if (prev && (!(prev & piece >> (4 * (i + 1))) || !hz_check(piece >> (4 * (i + 1)))))
			return (0);
	}
	return (1);
}

/*
** Verifie si la ligne comprend 4 caracteres ou 0 selon les cas desires.
** Si on se trouve sur une ligne en position 4 (c'est a dire, une ligne censee
** etre vide), alors on verifie qu'elle est bien vide, sinon qu'elle ne fait
** bien que 4 caracteres
*/

static unsigned short		line_to_byte(char *line, t_fillit_line *st)
{
	unsigned short	byte;
	short			i;

	byte = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == FILLED)
		{
			byte |= 1;
			st->block_nb++;
		}
		if (i < 3)
			byte = byte << 1;
	}
	return (byte);
}

int							map_piece(char *line, t_fillit_line *st)
{
	if (st->cur_line_pos == 4)
		return (!ft_strlen(line) ? 1 : 0);
	if (ft_strlen(line) != 4)
		return (0);
	st->inst->piece[st->inst->piece_nb] |= line_to_byte(line, st);
	if (st->cur_line_pos < 3)
		st->inst->piece[st->inst->piece_nb] <<= 4;
	return (1);
}

/*
** cur_line_nb: number of the current line
** cur_line_pos: position of the current line (between 0 and 4, 0 - 3 means
	we're in as piece of the game, 4 is a separator)
** block_nb: number of block of the current piece
** prev_pos: position of the previous piece
**
*/
int							get_line_info(char *line)
{
	static t_fillit_line st = {0, 0, 0, -1, NULL};

	if (!st.inst)
		st.inst = get_instance();
	st.cur_line_nb++;
	E(0, map_piece(line, &st), WRONG_FORMAT, FORCE_EXIT);
	if (st.cur_line_pos == 3)
	{
		E(0, st.block_nb == 4, WRONG_FORMAT, FORCE_EXIT);
		E(0, check_contiguous(st.inst->piece[st.inst->piece_nb]), WRONG_CONT, FORCE_EXIT);
		st.block_nb = 0;
		st.inst->piece_nb++;
	}
	st.cur_line_pos = (st.cur_line_pos + 1) % 5;
	return (1);
}