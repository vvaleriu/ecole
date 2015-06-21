/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_d_j.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:03:21 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 14:46:32 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** itoa sur le nombre. Len = len(s). Si flags '+' alors.
** si flag '-' alors on ecrit les espaces. On ecrit le nombre. On ecrit les
** espaces a la fin si necessaire.
*/

int			pf_print_d_j(long int n, t_pf_flag *fl)
{
	int		i;
	char	*s;
	int		len;
	int		tmp_len;

	i = 0;
	s = ft_itoa_long(n);
	len = (n >= 0 && fl[PF_SHOW_SIGN].val == 1 ? ft_strlen(s) + 1 :\
		ft_strlen(s));
	tmp_len = (fl[PF_ACC].val > len ? fl[PF_ACC].val : len);
	if ((n < 0 || (n >= 0 && fl[PF_SHOW_SIGN].val)) && (fl[PF_ACC].val > len))
		tmp_len++;
	i += pf_print_d_long_before(fl, n, (fl[PF_ACC].val > len ? tmp_len : len));
	if (fl[PF_ACC].val > len)
		i += pf_repeat_char('0', (n < 0 || (n >= 0 && fl[PF_SHOW_SIGN].val) ?\
			fl[PF_ACC].val - len + 1 : fl[PF_ACC].val - len));
	if (n < 0)
		i += ft_putstr(s + 1);
	else
		i += ft_putstr(s);
	ft_strdel(&s);
	i += pf_print_d_long_after(fl, len);
	return (i);
}
