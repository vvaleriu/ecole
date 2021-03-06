/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 04:48:12 by mzapata           #+#    #+#             */
/*   Updated: 2016/06/27 11:17:11 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <ftp_common.h>

void	sig_handler(int signo)
{
	if (signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if (signo == SIGINT)
	{
		printf("received SIGINT\n");
		exit(1);
	}
	else if (signo == SIGKILL)
		printf("received SIGKILL\n");
	else if (signo == SIGSTOP)
		printf("received SIGSTOP\n");
}
