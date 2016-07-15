/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 00:04:47 by vincent           #+#    #+#             */
/*   Updated: 2016/07/15 02:24:00 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Recoit une map completee et verifie si elle satisfait mieux les criteres
** que la map precedemment enregirstree
*/
static short check_current_solution(char **map)
{
	t_fillit_inst	*inst;
	unsigned short	ln;

	inst = get_instance();
	if (!inst->len || inst->len >= (ln = map_len(map)))
	{
		/*if (la solution est plus en haut a gauche, on garde celle la)*/
		inst->len = ln;
		ft_memcpy((void *)inst->solution, (void *)map, sizeof(**map) * MSIZE * MSIZE);
		print_map(map);
	}
	return (0);
}

/*
** map : tableau ou l'on place les pieces
** pnb : (piece_nb) numero de la piece que l'on veut placer
** retours:
**
*/
short		main_recursion(char **map, unsigned short pnb)
{
	unsigned short	mcoord[2];
	t_fillit_inst	*inst;

	inst = get_instance();
	X = 0;
	Y = 0;
	if (pnb == inst->piece_nb - 1)
		return (check_current_solution(map));
	while (Y < MSIZE)
	{
		while (X < MSIZE)
		{
			if (fit_on_map(map, mcoord, pnb))
				main_recursion(map, pnb + 1);
			X++;
		}
		Y++;
	}
	return (0);
}

/*
Avec ce tableau donne (map)
et ce numero de piece donne (i)
Pour chaque case, si on peut rentrer la piece, on passe a la piece suivante
sinon on retourne 0;
*/