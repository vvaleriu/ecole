/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cursor_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:26:46 by vincent           #+#    #+#             */
/*   Updated: 2016/04/07 12:23:30 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

void		get_cursor_position(void)
{
	char	buf[500];
	int		rd;

	ft_putstr("\033[6n");
	rd = read(0, buf, 499);
	buf[rd] = 0;
	ft_putendl(buf);
}
