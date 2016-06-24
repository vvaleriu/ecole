/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_term_prop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 23:29:19 by vincent           #+#    #+#             */
/*   Updated: 2016/03/04 11:52:39 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

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
	if (!(term_name = getenv("TERM")))
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
