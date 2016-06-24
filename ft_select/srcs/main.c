/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 23:29:19 by vincent           #+#    #+#             */
/*   Updated: 2016/03/04 11:52:39 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Change terminam
*/

int		main(int ac, char **av)
{
	t_tconf	*conf;

	conf = get_instance();
	sig_catcher();
	if (ac < 2 || !av)
	{
		ft_printf("See usage.\n");
		return (0);
	}
	if (init_terminal(conf) == -1)
		exit(0);
	build_list(conf, ++av);
	print_list(conf);
	get_key(conf);
	return (0);
}
