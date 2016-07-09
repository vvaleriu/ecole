/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_o_hh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:31:49 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 14:52:02 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** itoa sur le nombre. Len = len(s). Si flags '+' alors.
** si flag '-' alors on ecrit les espaces. On ecrit le nombre. On ecrit les
** espaces a la fin si necessaire.
*/

int			pf_print_o_hh(unsigned char n, t_pf_flag *fl)
{
	int		i;
	char	*s;
	int		len;

	i = 0;
	s = (fl[PF_ACC].val != -1 && n == 0 ? ft_strdup("") : ft_otoa_char(n));
	len = (fl[PF_ALT_PRINT].val == 1 ? ft_strlen(s) + 1 : ft_strlen(s));
	i += pf_print_o_before(fl, len);
	i += ft_putstr(s);
	ft_strdel(&s);
	i += pf_print_o_after(fl, len);
	return (i);
}
