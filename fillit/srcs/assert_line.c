/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 23:50:39 by vincent           #+#    #+#             */
/*   Updated: 2016/07/09 00:34:20 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

/*
** Verifie si la ligne correspond a ce que l'on attend d'elle
*/

static int	isCharNumberOk(char *line, t_fillit_line *st)
{
	if (st->cur_line_pos && st->cur_line_pos % 4 == 0)
	{
		if (!ft_strlen(line))
			return (1);
		return (0);
	}
	if (ft_strlen(line) != 4)
		return (0);
	return (1);
}

/*
** Recupere les infos de fournie par la ligne
*/

static int	get_line_info(char *line, t_fillit_line *st)
{
	if (ft_strlen(line) == 4)
		while (*line)
		{
			if (*line == FILLED)
				st->block_nb++;
			line++;
		}
	return (1);
}

int			assert_line(char *line)
{
	static t_fillit_line st = {0, 0, 0, -1};

	st.cur_line_nb++;
	//ft_printf("l: %d, len: %u\n", st.cur_line_nb, ft_strlen(line));
	E(0, isCharNumberOk(line, &st), WRONG_FORMAT, FORCE_EXIT);
	get_line_info(line, &st);
	st.cur_line_pos = (st.cur_line_pos + 1) % 5;
	if (!st.cur_line_pos)
		ft_printf("blocs de la piece: %u\n", st.block_nb);
	st.block_nb = !st.cur_line_pos ? 0 : st.block_nb;
	return (1);
}
