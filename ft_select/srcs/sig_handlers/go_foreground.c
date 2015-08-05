/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_foreground.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 01:49:35 by vincent           #+#    #+#             */
/*   Updated: 2015/08/05 02:09:44 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		go_foreground(int signo)
{
	t_tconf *conf;

	conf = get_instance();
	if (signo == SIGCONT)
	{
		ft_putstr("\033[?1049h\033[H");
		print_list(conf);
		get_key(conf);
	}
}