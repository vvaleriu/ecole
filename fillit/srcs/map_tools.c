/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 07:44:18 by vincent           #+#    #+#             */
/*   Updated: 2016/07/15 02:10:41 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static short	get_origin_coordonates(short origin_coor[2], unsigned short piece)
{
	short		i;

	i = 0;
	while (i < 16 && !((piece << i) & 0x8000))
		i++;
	if (origin_coor)
	{
		origin_coor[0] = i % 4;
		origin_coor[1] = i / 4;
	}
	return (i);
}


/*
** Rempli un tableau avec les coordonnees relatives des 3 derniers blocs de la
** piece par rapport aux coordonnees du premier bloc ainsi les coordonnees
** absolues du premier bloc de la piece
** --------
** - i : nombre de decalage de bit pour arriver au premier bloc de la piece
** - found: blocs de la pieces restant a trouver
** - origin: coordonnees du premier point
** - rcoord[6]: coordonnees relatives des trois derniers blocs par rapport au
** 				premier
*/
void		get_relative_coordonates(short rcoord[8], unsigned short piece)
{
	short		i;
	short		found;

	found = 0;
	i = get_origin_coordonates(rcoord + 6, piece);
	while (++i < 16 && found < 6)
	{
		if ((piece << i) & 0x8000)
		{
			rcoord[found] = (i % 4) - AP0_X;
			rcoord[++found] = i / 4 - AP0_Y;
			found++;
		}
	}
}

/*
** Recoit des coordonnees du plan principales et les coordonnees relatives
** d'une piece et verifie si cette piece peut etre placee sur le plan
** Elle verifie aussi que la taille de la map avec la nouvelle piece n'est
** pas moins bonne que la meilleure taille trouvee. Si tel est le cas, alors
** elle renvoit 0
** SI tout est bon elle renvoit 1
** map: map contenant les piece
** mcoord: coordonnees de la map a partir desquelles on cherche a verifier
**		si la piece rentre
** pnb: numero de la piece
**
*/

short		fit_on_map(char **map, unsigned short mcoord[2], unsigned short pnb)
{
	t_fillit_inst *inst;
	short	*rcoord;

	inst = get_instance();
	rcoord = inst->p_rcoord[pnb];
	if (X + P1X < 0 || X + P1X > XY_MAX || Y + P1Y < 0 || Y + P1Y > XY_MAX || map[X + P1X][Y + P1Y] != EMPTY)
		return (0);
	if (X + P2X < 0 || X + P2X > XY_MAX || Y + P2Y < 0 || Y + P2Y > XY_MAX || map[X + P2X][Y + P2Y] != EMPTY)
		return (0);
	if (X + P3X < 0 || X + P3X > XY_MAX || Y + P3Y < 0 || Y + P3Y > XY_MAX || map[X + P3X][Y + P3Y] != EMPTY)
		return (0);
	map[Y][X] = (char)(pnb + 65);
	map[Y + P1Y][X + P1X] = (char)(pnb + 65);
	map[Y + P2Y][X + P2X] = (char)(pnb + 65);
	map[Y + P3Y][X + P3X] = (char)(pnb + 65);
	if (inst->len && map_len(map) > inst->len)
	{
		map[Y][X] = EMPTY;
		map[Y + P1Y][X + P1X] = EMPTY;
		map[Y + P2Y][X + P2X] = EMPTY;
		map[Y + P3Y][X + P3X] = EMPTY;
		return (0);
	}
	return (1);
}

/*short		fit_on_map(char **map, short mcoord[2], short rcoord[8])
{
	t_fillit_inst *inst;

	inst = get_instance();
	if (X + P1X < 0 || X + P1X > XY_MAX || Y + P1Y < 0 || Y + P1Y > XY_MAX || map[X + P1X][Y + P1Y] != EMPTY)
		return (0);
	if (X + P2X < 0 || X + P2X > XY_MAX || Y + P2Y < 0 || Y + P2Y > XY_MAX || map[X + P2X][Y + P2Y] != EMPTY)
		return (0);
	if (X + P3X < 0 || X + P3X > XY_MAX || Y + P3Y < 0 || Y + P3Y > XY_MAX || map[X + P3X][Y + P3Y] != EMPTY)
		return (0);
	map[Y][X] = FILLED;
	map[Y + P1Y][X + P1X] = FILLED;
	map[Y + P2Y][X + P2X] = FILLED;
	map[Y + P3Y][X + P3X] = FILLED;
	return (1);
}*/