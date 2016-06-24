/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 18:03:18 by vincent           #+#    #+#             */
/*   Updated: 2016/03/10 11:06:30 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** ft_printf("List_size: %d, row: %d - col: %d\n", ft_dlstlen(conf->list),
** conf->w.ws_row, conf->w.ws_col);
*/

void		resize_list(int signo)
{
	t_tconf			*conf;
	struct winsize	new_size;

	if (signo == SIGWINCH)
	{
		conf = get_instance();
		ioctl(0, TIOCGWINSZ, &new_size);
		conf->w.ws_row = new_size.ws_row;
		conf->w.ws_col = new_size.ws_col;
		if (conf->w.ws_row <= 10 || conf->w.ws_col < 15)
			print_small_size_error(conf);
		else
			print_list(conf);
	}
}
