/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_term_attr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 23:28:18 by vincent           #+#    #+#             */
/*   Updated: 2016/03/10 14:54:14 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

int				change_term_attr(t_tconf *conf)
{
	conf->cur.c_lflag &= ~(ICANON | ECHO);
	conf->cur.c_lflag |= (ISIG);
	conf->cur.c_cc[VMIN] = 1;
	conf->cur.c_cc[VTIME] = 0;
	set_str_cap("cl:ti");
	return (err_int(-1, tcsetattr(0, TCSADRAIN, &conf->cur), ERR_SET_TERM_CAPS, 0));
}