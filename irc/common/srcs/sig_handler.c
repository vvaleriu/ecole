/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 04:48:12 by mzapata           #+#    #+#             */
/*   Updated: 2015/03/06 14:16:52 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <ftp_common.h>

void	sig_handler(int signo)
{
	if (signo == SIGUSR1)
		ft_printf("received SIGUSR1\n");
	else if (signo == SIGINT)
	{
		ft_printf("received SIGINT\n");
		exit(1);
	}
	else if (signo == SIGKILL)
		ft_printf("received SIGKILL\n");
	else if (signo == SIGSTOP)
		ft_printf("received SIGSTOP\n");
}
