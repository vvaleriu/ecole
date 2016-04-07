/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 01:48:19 by vincent           #+#    #+#             */
/*   Updated: 2016/04/07 11:48:55 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

void		go_background(int signo)
{
	char	cp[2];
	t_tconf *conf;

	conf = get_instance()->conf;
	(void)signo;
	if (isatty(1))
	{
		cp[0] = conf->cur.c_cc[VSUSP];
		cp[1] = 0;
		tputs(tgetstr("te", NULL), 1, putchar_int);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, cp);
	}
}
