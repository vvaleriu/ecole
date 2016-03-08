/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 04:48:12 by mzapata           #+#    #+#             */
/*   Updated: 2015/08/02 13:21:51 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		sig_handler(int signo)
{
	if (signo == SIGUSR1)
		ft_printf("received SIGUSR1\n");
	else if (signo == SIGKILL)
		ft_printf("received SIGKILL\n");
	else if (signo == SIGSTOP)
		ft_printf("received SIGSTOP\n");
}
