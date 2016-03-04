/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 18:03:18 by vincent           #+#    #+#             */
/*   Updated: 2016/03/04 14:43:10 by vincent          ###   ########.fr       */
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
		if (conf->w.ws_row <= 10 || conf->w.ws_col < 15)
			print_small_size_error(conf);
		else
			print_list(conf);
	}
}
