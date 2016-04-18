/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_x_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:34:55 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 15:05:21 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** itoa sur le nombre. Len = len(s). Si flags '+' alors.
** si flag '-' alors on ecrit les espaces. On ecrit le nombre. On ecrit les
** espaces a la fin si necessaire.
*/

int			pf_print_x_long(unsigned long int n, t_pf_flag *fl)
{
	int		i;
	char	*s;
	int		len;

	i = 0;
	s = ft_itoh_long(n);
	len = (fl[PF_ALT_PRINT].val == 1 ? ft_strlen(s) + 2 : ft_strlen(s));
	i += pf_print_x_before(fl, len, n);
	i += ft_putstr(s);
	ft_strdel(&s);
	i += pf_print_x_after(fl, i);
	return (i);
}
