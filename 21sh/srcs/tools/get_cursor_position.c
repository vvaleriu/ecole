/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cursor_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 11:26:46 by vincent           #+#    #+#             */
/*   Updated: 2016/04/04 11:29:29 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void		get_cursor_position()
{
	char	buf[500];
	int		rd;

	ft_putstr("\033[6n");
	rd = read(0, buf, 499);
	buf[rd] = 0;
	ft_putendl(buf);
}