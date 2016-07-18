/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 23:16:51 by vincent           #+#    #+#             */
/*   Updated: 2016/07/17 23:08:45 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*static void print_pieces_short_value(t_fillit_inst *inst)
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
}*/

static char		**create_array(t_fillit_inst *inst)
{
	char	*tmp;
	char	**ret;
	int		i;

	i = -1;
	tmp = (char *)ft_memalloc(sizeof(*tmp) * LEN_MAX * LEN_MAX);
	if (!tmp)
		return (NULL);
	ft_memset((void *)tmp, '.', LEN_MAX * LEN_MAX);
	ret = (char **)ft_memalloc(sizeof(*ret) * LEN_MAX);
	if (!ret)
		return (NULL);
	while (++i < LEN_MAX)
		ret[i] = tmp + (i * LEN_MAX);
	return (ret);
}

/*
** Pour chaque piece (representation binaire de la piece), calcule et remplit
** les coordonnees relatives (utilisees pour les placer sur le plan)
*/
static void 	fill_p_rcoord(t_fillit_inst *inst)
{
	int		i;

	i = -1;
	while (++i < inst->piece_nb)
		get_relative_coordonates(inst->p_rcoord[i], inst->piece[i]);
	LEN_MAX = inst->piece_nb + 4 - 1;
}

int			main(int ac, const char **av)
{
	t_fillit_inst	*inst;
	char			**map;

	inst = get_instance();
	E(1, ac != 2, USAGE, FORCE_EXIT);
	open_file(av[1]);
	fill_p_rcoord(inst);
	EV(NULL, (map = create_array(inst)), MALLOC_FAILED, FORCE_EXIT);
	EV(NULL, (inst->solution = create_array(inst)), MALLOC_FAILED, FORCE_EXIT);
	//map = create_array(inst);
	//inst->solution = create_array(inst);
	main_recursion(inst, map, 0);
	print_solution_map(inst->solution);
	return (0);
}