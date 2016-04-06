/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_filename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 09:17:42 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/06 10:24:24 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

int			is_filename(char c)
{
	if (ft_isspace(c) || c == '&' || c == '|' || c == ';')
		return (0);
	if (ft_isalnum(c))
		return (1);
	if (c == 35 || c == 37 || (c > 41 && c < 48) || c == 63 || c == 64 || c == \
		94 || c == 95 || c == 126)
		return (1);
	return (0);
}