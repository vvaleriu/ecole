/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fixed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:40:11 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/25 17:59:03 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void		ft_putchar_fixed(char c)
{
	t_var	*var;
	t_tconf	*conf;

	var = get_instance();
	conf = var->conf;
	set_str_cap("im:kI");
	write(conf->wfd, &c, 1);
	set_str_cap("kM:ei");
}