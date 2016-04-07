/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_win_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:04:14 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:02:53 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

/*
** t_printf("List_size: %d, row: %d - col: %d\n", ft_dlstlen(conf->list), \
** conf->w.ws_row, conf->w.ws_col);
*/

void		update_win_size(int signo)
{
	t_tconf			*conf;
	struct winsize	new_size;

	if (signo == SIGWINCH)
	{
		conf = get_instance()->conf;
		ioctl(0, TIOCGWINSZ, &new_size);
		conf->w.ws_row = new_size.ws_row;
		conf->w.ws_col = new_size.ws_col;
	}
}
