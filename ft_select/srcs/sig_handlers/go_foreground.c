/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_foreground.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 01:49:35 by vincent           #+#    #+#             */
/*   Updated: 2015/08/05 02:39:57 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		go_foreground(int signo)
{
	t_tconf *conf;

	(void)signo;
	conf = get_instance();
	tputs(tgetstr("ti", NULL), 1, putchar_int);
	tcsetattr(0, TCSADRAIN, &conf->cur);
	signal(SIGTSTP, go_background);
	print_list(conf);
}
