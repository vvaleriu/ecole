/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 07:26:26 by vincent           #+#    #+#             */
/*   Updated: 2016/07/15 02:24:41 by vincent          ###   ########.fr       */
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
		return ((instance = (t_fillit_inst*)ft_memalloc(sizeof(*instance))));
	return (instance);
}

void			print_map(char **map)
{
	unsigned short	mcoord[2] = {0};
	t_fillit_inst	*inst;
	unsigned short	max;

	inst = get_instance();
	max = inst->len ? inst->len : MSIZE;
	ft_putendl("MAP:");
	while (Y < max)
	{
		while (X < max)
		{
			ft_putchar(map[Y][X] == 0 ? '.' : map[Y][X]);
			X++;
		}
		ft_putchar('\n');
		X = 0;
		Y++;
	}
	ft_putchar('\n');
}

static unsigned short	get_x_len(char *line)
{
	short	i;
	unsigned short	first;
	unsigned short	last;

	first = 0;
	last = 0;
	i = -1;
	while (++i < MSIZE)
		if (line[i] != EMPTY)
		{
			if (!first)
			{
				first = i + 1;
				last = first;
			}
			else
				last = i + 1;
		}
	return ((!last && !first ? 0 : 1) + last - first);
}

unsigned short			map_len(char **map)
{
	unsigned short	mcoord[2] = {-1, -1};
	short			x_len;
	unsigned short	max_x_len;
	unsigned short	first;
	unsigned short	last;

	x_len = 0;
	max_x_len = 0;
	first = 0;
	last = 0;
	while (++Y < MSIZE)
		while (++X < MSIZE)
		{
			x_len = get_x_len(map[X]);
			if (x_len)
			{
				max_x_len = max(x_len, max_x_len);
				if (!first)
				{
					first = X + 1;
					last = first;
				}
				else
					last = X + 1;
			}
		}
	return max((!last && !first ? 0 : 1) + last - first, max_x_len);
}
