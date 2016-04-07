/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_term_prop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 10:01:31 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 11:51:16 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

/*
** getenv : Recupere le nom du terminal dans les vars env
** tgetent : verfie si on peut recuperer les infos du terminal
** tcgetattr : remplit la structure termios avec les possibilités du terminal.
** 		on remplie une structure que l'on ne va pas modifier pour
** la restaurer par la suite et une que l'on va modifier a notre convenance
*/

int			load_term_prop(t_tconf *conf)
{
	char	*term_name;
	int		success;

	term_name = NULL;
	if (!(term_name = get_env_value("TERM", get_instance()->tenv)))
		return (-1);
	success = tgetent(conf->term_buffer, term_name);
	if (success == -1)
		ft_putendl(ERR_TERM_DB);
	else if (success == 0)
		ft_putendl(ERR_TERM_UNDEF);
	if (tcgetattr(0, &conf->def) == -1 || tcgetattr(0, &conf->cur) == -1)
		return (-1);
	return (success);
}
