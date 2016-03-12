/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_cursor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:26:54 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/12 23:06:38 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ft_minishell2.h>

void		ft_putstr_cursor(char *str)
{
	t_var	*var;
	t_tconf	*conf;

	var = get_instance();
	conf = var->conf;
	set_str_cap("im");
	while (*str != '\0')
	{
		write(conf->fd, &(*str), 1);
		str++;
		var->line.pos++;
	}
	set_str_cap("ei");
}