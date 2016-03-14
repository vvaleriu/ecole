/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fixed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:40:58 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/14 14:07:38 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void		ft_putstr_fixed(char *str)
{
	t_var	*var;
	t_tconf	*conf;

	var = get_instance();
	conf = var->conf;
	set_str_cap("im");
	while (*str != '\0')
	{
		set_str_cap("kI");
		write(conf->fd, &(*str), 1);
		set_str_cap("kM");
		str++;
	}
	set_str_cap("ei");
}