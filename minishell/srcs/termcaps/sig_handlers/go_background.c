/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 01:48:19 by vincent           #+#    #+#             */
/*   Updated: 2015/08/05 02:39:54 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		go_background(int signo)
{
	char	cp[2];
	t_tconf *conf;

	conf = get_instance();
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