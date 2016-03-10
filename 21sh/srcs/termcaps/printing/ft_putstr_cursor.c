/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_cursor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:26:54 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/10 12:47:41 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ft_minishell2.h>

void		ft_putstr_cursor(char *str)
{
	t_tconf	*conf;

	conf = get_instance()->conf;
	while (*str != '\0')
	{
		ft_putchar_cursor(*str);
		str++;
	}
}