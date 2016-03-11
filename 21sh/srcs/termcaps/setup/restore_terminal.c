/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_terminal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 08:16:31 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/11 23:14:43 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** te : fin du programme permettant de bouger le curseur
** ei : fin du mode d'insertion
*/
int			restore_terminal(t_var *var)
{
	t_tconf		*conf;

	conf = var->conf;
	if (tcsetattr(0, TCSADRAIN, &conf->def) == -1)
	{
		ft_putendl("Error restoring default terminal capabilities.");
		exit(-1);
	}
	set_str_cap("te");
	close(conf->fd);
	conf->cur.c_lflag = (ICANON | ECHO | ISIG);
	return (-1);
}