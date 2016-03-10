/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_win_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:04:14 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/10 11:07:15 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void		update_win_size(int signo)
{
	t_tconf		*conf;
	struct		winsize new_size;

	if (signo == SIGWINCH)
	{
		conf = get_instance()->conf;
		ioctl(0, TIOCGWINSZ, &new_size);
		conf->w.ws_row = new_size.ws_row;
		conf->w.ws_col = new_size.ws_col;
		//ft_printf("List_size: %d, row: %d - col: %d\n", ft_dlstlen(conf->list), conf->w.ws_row, conf->w.ws_col);
	}
}