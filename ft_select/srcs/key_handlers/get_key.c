/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:38:44 by vincent           #+#    #+#             */
/*   Updated: 2015/08/02 03:01:32 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			get_key(t_tconf *conf)
{
	char key_buf[KEY_SIZE];

	while (conf->run)
	{
		read(0, key_buf, KEY_SIZE);
		if (key_buf[0] == 27)
			handle_arrow();
		else if (key_buf[0] == 10)
		{
			handle_return(conf);
			conf->run = 0;
		}
	}
	return (0);
}