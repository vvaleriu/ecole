/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 18:03:18 by vincent           #+#    #+#             */
/*   Updated: 2015/08/02 03:10:35 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		get_screen_size(int signo)
{
	t_tconf		*conf;
	struct		winsize new_size;

	if (signo == SIGWINCH)
	{
		conf = get_instance();
		ioctl(0, TIOCGWINSZ, &new_size);
		conf->w.ws_row = new_size.ws_row;
		conf->w.ws_col = new_size.ws_col;
		set_str_cap("cl");
		print_list(conf);
		//ft_printf("row: %d - col: %d\n", conf->w.ws_row, conf->w.ws_col);
	}
}

/*
static void		update_size(struct winsize new_size, t_tconf *conf)
{
	conf->w.ws_row = new_size.ws_row;
	conf->w.ws_col = new_size.ws_col;
}

void		get_screen_size(int signo)
{
	struct winsize new_size;

	if (signo == SIGWINCH)
	{
		ioctl(0, TIOCGWINSZ, &new_size);
		update_size(new_size, &conf);
		set_str_cap("cl");
		print_list(&conf);
		//ft_printf("row: %d - col: %d\n", conf.w.ws_row, conf.w.ws_col);
	}
}
*/