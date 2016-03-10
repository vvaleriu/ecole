/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_cursor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:40:11 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/10 15:12:26 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void		ft_putchar_cursor(char c)
{
	t_tconf	*conf;

	conf = get_instance()->conf;
	write(conf->fd, &c, 1);
	//move_to_next_char(get_instance());
}