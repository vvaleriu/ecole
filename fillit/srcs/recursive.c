/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 00:04:47 by vincent           #+#    #+#             */
/*   Updated: 2016/07/18 08:12:33 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>
#include <unistd.h>

static unsigned short	find_letter_in_solution(char **map, t_fillit_inst *inst, unsigned short piece)
{
	unsigned short	mcoord[2];
	char			letter;

	X = -1;
	Y = -1;
	letter = (char)(piece + 65);
	while (++Y < LEN_MAX)
	{
		while (++X < LEN_MAX)
		{
			if (inst->solution[Y][X] == letter)
			{
				if (map[Y][X] != letter)
					return (-1);
				return (0);
			}
			else if (map[Y][X] == letter)
				return (1);
		}
		X = -1;
	}
	return (0);
}

static short	is_solution_better(char **map, t_fillit_inst *inst)
{
	unsigned short	piece;
	unsigned short	ret;

	piece = 0;
	while (piece < inst->piece_nb)
	{
		if ((ret = find_letter_in_solution(map, inst, piece)) != 0)
			return (ret);
		piece++;
	}
	return (0);
}

/*
** Recoit une map completee et verifie si elle satisfait mieux les criteres
** que la map precedemment enregirstree
*/
static short 	check_current_solution(char **map)
{
	t_fillit_inst	*inst;
	unsigned short	ln;

	inst = get_instance();
	ln = map_len(inst , map);
	if (!inst->len || inst->len >= ln)
	{
		if (ln == inst->len)
		{
			if (is_solution_better(map, inst) == 1)
				ft_memcpy((void *)*(inst->solution), (void *)*map, sizeof(char) * LEN_MAX * LEN_MAX);
		}
		else
		{
			inst->len = ln;
			ft_memcpy((void *)*inst->solution, (void *)*map, sizeof(char) * LEN_MAX * LEN_MAX);
		}
	}
	return (0);
}

/*
** map : tableau ou l'on place les pieces
** pnb : (piece_nb) numero de la piece que l'on veut placer
** retours:
**
*/
short			main_recursion(t_fillit_inst *inst, char **map, unsigned short pnb)
{
	unsigned short	mcoord[2];

	X = -1;
	Y = -1;
	while (++Y < LEN_MAX)
	{
		while (++X < LEN_MAX)
			if (fit_on_map(inst, map, mcoord, pnb))
			{
				if (pnb == inst->piece_nb - 1)
				{
					if (X == LEN_MAX - 1)
						return (check_current_solution(map));
					check_current_solution(map);
					delete_from_map(map, mcoord, pnb);
				}
				else if (!main_recursion(inst, map, pnb + 1))
					delete_from_map(map, mcoord, pnb);
			}
		X = -1;
	}
	return (0);
}
