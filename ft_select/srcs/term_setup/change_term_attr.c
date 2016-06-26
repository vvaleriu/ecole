/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_term_attr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 23:28:18 by vincent           #+#    #+#             */
/*   Updated: 2016/03/04 12:36:05 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int				change_term_attr(t_tconf *conf)
{
	conf->cur.c_lflag &= ~(ICANON | ECHO);
	conf->cur.c_lflag |= (ISIG);
	conf->cur.c_cc[VMIN] = 1;
	conf->cur.c_cc[VTIME] = 0;
	set_str_cap("vi:ti");
	return (err_int(-1, tcsetattr(0, TCSADRAIN, &conf->cur),
		ERR_SET_TERM_CAPS, 0));
}
