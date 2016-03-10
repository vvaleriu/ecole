/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_foreground.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 01:49:35 by vincent           #+#    #+#             */
/*   Updated: 2016/03/10 12:02:20 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void		go_foreground(int signo)
{
	t_tconf *conf;

	(void)signo;
	conf = get_instance()->conf;
	tputs(tgetstr("ti", NULL), 1, putchar_int);
	tcsetattr(0, TCSADRAIN, &conf->cur);
	signal(SIGTSTP, go_background);
}