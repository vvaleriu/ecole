/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 04:48:12 by mzapata           #+#    #+#             */
/*   Updated: 2016/03/10 15:17:05 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void		sig_handler(int signo)
{
	if (signo == SIGUSR1)
	{
		ft_printf("received SIGUSR1\n");
		exit(0);
	}
	else if (signo == SIGKILL)
	{
		ft_printf("received SIGKILL\n");
		exit(0);
	}
	else if (signo == SIGSTOP)
	{
		ft_printf("received SIGSTOP\n");
		exit(0);
	}
	else
	{
		exit(0);
	}
}
