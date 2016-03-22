/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_modes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 23:28:18 by vincent           #+#    #+#             */
/*   Updated: 2016/03/22 15:56:20 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** cl : on nettoie l'ecran
** ti : on s'autorise a bouger le curseur
** im : mode d'insertion
*/
int				terminal_input_mode(t_tconf *conf)
{
	conf->cur.c_lflag &= ~(ICANON | ECHO | ECHOE);
	conf->cur.c_lflag |= (ISIG);
	conf->cur.c_cc[VMIN] = 1;
	conf->cur.c_cc[VTIME] = 0;
	return (err_int(-1, tcsetattr(STDIN_FILENO, TCSADRAIN, &conf->cur), \
		ERR_SET_TERM_CAPS, 0));
}

int				terminal_execute_mode(t_tconf *conf)
{
	conf->cur.c_lflag &= (ICANON | ECHO | ECHOE);
	conf->cur.c_lflag |= (ISIG);
	set_str_cap("te");
	//close(conf->fd);
	return (err_int(-1, tcsetattr(STDIN_FILENO, TCSADRAIN, &conf->def), \
		ERR_SET_TERM_CAPS, 0));
}