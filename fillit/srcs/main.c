/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 23:16:51 by vincent           #+#    #+#             */
/*   Updated: 2016/07/15 02:28:39 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void print_pieces_short_value(t_fillit_inst *inst)
{
	int		i;

	i = -1;
	while (++i < inst->piece_nb)
		if (inst->piece[i])
			ft_printf("valeur piece(%d): %u\n", i, inst->piece[i]);
}

static void	print_all_pcoord(t_fillit_inst *inst)
{
	int		i;
	short	*rcoord;

	i = -1;
	while (++i < inst->piece_nb)
	{
		rcoord = inst->p_rcoord[i];
		ft_printf("[%d] AP0(%d, %d), P1(%d, %d) P2(%d, %d) P3(%d, %d):\n",
			i, AP0_X, AP0_Y, P1X, P1Y, P2X, P2Y, P3X, P3Y);
	}
}

/*
** Pour chaque piece (representation binaire de la piece), calcule et remplit
** les coordonnees relatives (utilisees pour les placer sur le plan)
*/
static void fill_p_rcoord(t_fillit_inst *inst)
{
	int		i;

	i = -1;
	while (++i < inst->piece_nb)
		get_relative_coordonates(inst->p_rcoord[i], inst->piece[i]);
}

static char	**create_map(void)
{
	char	**map;
	char 	*tmp;
	int		i;

	i = 0;
	map = (char **)ft_memalloc(sizeof(char *) * MSIZE);
	tmp = (char *)ft_memalloc(sizeof(char) * MSIZE * MSIZE);
	ft_memset((void *)tmp, '.', MSIZE * MSIZE);
	while (i < MSIZE)
	{
		map[i] = tmp + (i * MSIZE);
		i++;
	}
	return (map);
}

int			main(int ac, const char **av)
{
	t_fillit_inst	*inst;
	char			**map;

	inst = get_instance();
	E(1, ac != 2, USAGE, FORCE_EXIT);
	open_file(av[1]);
	map = create_map();
	inst->solution = create_map();
	fill_p_rcoord(inst);


	print_pieces_short_value(inst);
	print_all_pcoord(inst);

	/*unsigned short mcoord[2] = {0, 0};
	fit_on_map(map, mcoord, 3);
	ft_printf("len: %u", map_len(map));
	print_map(map);*/

	main_recursion(map, 0);
	//print_map(inst->solution);
	return (0);
}