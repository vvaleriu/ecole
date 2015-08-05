/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 01:48:19 by vincent           #+#    #+#             */
/*   Updated: 2015/08/05 02:09:46 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		go_background(int signo)
{
	t_tconf *conf;

	conf = get_instance();
	if (signo == SIGTSTP)
		tcsetattr(0, TCSADRAIN, &conf->def);
}