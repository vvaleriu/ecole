/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 18:03:18 by vincent           #+#    #+#             */
/*   Updated: 2015/08/05 02:44:49 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		resize_list(int signo)
{
	t_tconf		*conf;
	struct		winsize new_size;

	if (signo == SIGWINCH)
	{
		conf = get_instance();
		ioctl(0, TIOCGWINSZ, &new_size);
		conf->w.ws_row = new_size.ws_row;
		conf->w.ws_col = new_size.ws_col;
		//ft_printf("List_size: %d, row: %d - col: %d\n", ft_dlstlen(conf->list), conf->w.ws_row, conf->w.ws_col);
		/*iif (conf->w.ws_row < 5 || conf->w.ws_col < 15)
			resize_list(SIGWINCH);*/
		if (conf->w.ws_row < 2 || conf->w.ws_col < 10)
			print_small_size_error();
		print_list(conf);
	}
}
