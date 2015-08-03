/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/02 17:12:15 by vincent           #+#    #+#             */
/*   Updated: 2015/08/03 19:48:23 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
**
*/

int			close_program(t_tconf *conf, char *key_buf)
{
	if (tcsetattr(0, TCSADRAIN, &conf->def) == -1)
		ft_putendl("Error restoring default terminal capabilities.");
	exit_clean(conf);
	if (ft_strlen(key_buf) < 1000)
		ft_putstr("lol");
	ft_putstr("\033[?1049l");
	return (-1);
}