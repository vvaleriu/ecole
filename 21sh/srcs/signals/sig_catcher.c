/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_catcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 01:59:46 by vincent           #+#    #+#             */
/*   Updated: 2016/04/05 16:04:28 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void			sig_catcher()
{
	signal(SIGINT, sig_handler);
	signal(SIGKILL, sig_handler);
	//signal(SIGTSTP, SIG_IGN);
	signal(SIGWINCH, update_win_size);
}

void			sig_catcher_fork()
{
	signal(SIGINT, sig_handler_fork);
}