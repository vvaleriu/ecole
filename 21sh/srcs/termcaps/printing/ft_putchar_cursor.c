/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_cursor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:40:11 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/14 12:39:07 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void		ft_putchar_cursor(char c)
{
	t_var	*var;
	t_tconf	*conf;

	var = get_instance();
	conf = var->conf;
	set_str_cap("im");
	write(conf->fd, &c, 1);
	set_str_cap("ei");
	var->line.pos++;
}