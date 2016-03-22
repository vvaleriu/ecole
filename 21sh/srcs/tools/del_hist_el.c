/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_hist_el.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:47:37 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/16 12:27:15 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void		del_hist_el(void *p, size_t size)
{
	char	*str;

	str = (char *)p;
	(void)size;
	ft_strdel(&str);
	p = NULL;
}