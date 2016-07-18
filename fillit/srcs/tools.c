/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 07:26:26 by vincent           #+#    #+#             */
/*   Updated: 2016/07/17 00:24:30 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

unsigned short	max(unsigned short a, unsigned short b)
{
	return (a >= b ? a : b);
}

t_fillit_inst	*get_instance(void)
{
	static t_fillit_inst *instance = NULL;

	if (!instance)
	{
		instance = (t_fillit_inst*)ft_memalloc(sizeof(*instance));
		instance->len = 0;
		instance->xlen = 0;
		instance->ylen = 0;
		instance->piece_nb = 0;
		instance->len_max = 0;
	}
	return (instance);
}

void			print_map(char **map)
{
	unsigned short	mcoord[2] = {0};
	t_fillit_inst	*inst;
	unsigned short	max;

	inst = get_instance();
	max = LEN_MAX;

	//	ft_printf("MAP (%u):\n", map_len(inst, map));
	while (Y < max)
	{
		while (X < max)
		{
			ft_putchar(map[Y][X]);
			X++;
		}
		ft_putchar('\n');
		X = 0;
		Y++;
	}
	ft_putchar('\n');
}

void			print_solution_map(char **map)
{
	unsigned short	mcoord[2] = {0};
	t_fillit_inst	*inst;

	inst = get_instance();
	ft_printf("MAP (%u):\n", map_len(inst, map));
	while (Y < inst->ylen)
	{
		while (X < inst->xlen)
		{
			ft_putchar(map[Y][X]);
			X++;
		}
		ft_putchar('\n');
		X = 0;
		Y++;
	}
	ft_putchar('\n');
}

unsigned short			map_len(t_fillit_inst *inst, char **map)
{
	unsigned short	mcoord[2] = {-1, -1};
	short			sh[5] = {-1, -1, -1, -1, -1};

	EMPTY_LINE = 1;
	while (++Y < LEN_MAX)
	{
		while (++X < LEN_MAX)
		{
			if (map[Y][X] != EMPTY)
				EMPTY_LINE = 0;
			if ((map[Y][X] != EMPTY && X < XFIRST) || (map[Y][X] != EMPTY && XFIRST < 0))
				XFIRST = X;
			if ((map[Y][X] != EMPTY && X > XLAST) || (map[Y][X] != EMPTY && XLAST < 0))
				XLAST = X;
		}
		if (YFIRST < 0 && !EMPTY_LINE)
			YFIRST = Y;
		if (!EMPTY_LINE)
			YLAST = Y;
		X = -1;
		EMPTY_LINE = 1;
	}
	return max((inst->xlen = 1 + XLAST - XFIRST), (inst->ylen = 1 + YLAST - YFIRST));
}
