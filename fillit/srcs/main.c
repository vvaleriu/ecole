/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 23:16:51 by vincent           #+#    #+#             */
/*   Updated: 2016/07/12 15:54:39 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void debug_pieces(t_fillit_inst *inst)
{
	int		i;

	i = 0;
	while (i < inst->piece_nb)
	{
		if (inst->piece[i])
			ft_printf("valeur piece(%d): %u\n", i, inst->piece[i]);
		i++;
	}
}

int			main(int ac, const char **av)
{
	if (ac != 2)
	{
		ft_printf("usage: %s\n", USAGE);
		return (0);
	}
	open_file(av[1]);
	debug_pieces(get_instance());
	return (0);
}