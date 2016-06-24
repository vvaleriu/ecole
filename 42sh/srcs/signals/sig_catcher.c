/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_catcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 01:59:46 by vincent           #+#    #+#             */
/*   Updated: 2016/04/07 11:49:45 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>

void			sig_catcher(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGKILL, sig_handler);
	signal(SIGWINCH, update_win_size);
}

void			sig_catcher_fork(void)
{
	signal(SIGINT, sig_handler_fork);
}
