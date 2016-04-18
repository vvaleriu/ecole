/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 04:48:12 by mzapata           #+#    #+#             */
/*   Updated: 2016/04/07 11:48:31 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

void		sig_handler(int signo)
{
	t_var	*var;

	var = get_instance();
	if (signo == SIGINT)
		move_to_next_line(get_instance());
}

void		sig_handler_fork(int signo)
{
	if (signo == SIGINT)
		kill(getpid(), SIGINT);
}
