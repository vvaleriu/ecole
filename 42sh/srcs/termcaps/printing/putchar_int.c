/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:09:41 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>

int		putchar_int(int c)
{
	write(get_instance()->conf->wfd, &c, 1);
	return (1);
}
