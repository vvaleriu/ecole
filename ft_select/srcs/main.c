/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 23:29:19 by vincent           #+#    #+#             */
/*   Updated: 2015/08/02 03:11:47 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int 		main(int ac, char **av)
{
	t_tconf	*conf;

	conf = get_instance();
	sig_catcher();
	ft_putstr("\033[?1049h\033[H");
	if (ac < 2 || !av)
	{
		ft_printf("See usage.\n");
		return (0);
	}
	init_terminal(conf);
	build_list(conf, ++av);
	//deb_list(conf);
	print_list(conf);
	get_key(conf);
	return (0);
}