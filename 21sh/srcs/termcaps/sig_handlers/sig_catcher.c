/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_catcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 01:59:46 by vincent           #+#    #+#             */
/*   Updated: 2015/08/05 02:41:40 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*static void		sig_int(int signo)
{
	t_tconf *conf;

	if (signo == SIGINT)
	{
		conf = get_instance();
		close_program(conf, NULL);
	}
}*/

void			sig_catcher()
{
	signal(SIGINT, SIG_IGN);
	signal(SIGWINCH, resize_list);
	signal(SIGTSTP, go_background);
	signal(SIGCONT, go_foreground);
}