/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:03:49 by vincent           #+#    #+#             */
/*   Updated: 2015/08/02 01:34:36 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			init_terminal(t_tconf *conf)
{
	conf->run = 1;
	conf->list = NULL;
	ioctl(0, TIOCGWINSZ, &(conf->w));
	if (load_term_prop(conf) <= 0)
		return (-1);
	//return (change_term_attr(conf));
	return (1);
}