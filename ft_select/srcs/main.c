/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 23:29:19 by vincent           #+#    #+#             */
/*   Updated: 2015/08/01 01:37:12 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int 		main(int ac, char **av)
{
	sig_catcher();
	ft_putstr("\033[?1049h\033[H");
	if (ac < 2 || !av)
	{
		ft_printf("See usage.\n");
		return (0);
	}
	init_terminal(&conf);
	print_list(++av);
	get_key();
	return (0);
}