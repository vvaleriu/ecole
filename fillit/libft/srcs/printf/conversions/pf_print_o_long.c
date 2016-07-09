/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_o_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:31:49 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 14:52:47 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		pf_print_o_long(unsigned long int n, t_pf_flag *fl)
{
	int		i;
	char	*s;
	int		len;

	i = 0;
	s = ((fl[PF_ACC].val != -1 && !n) || (fl[PF_ALT_PRINT].val && !n) ?\
		ft_strdup("") : ft_otoa_long(n));
	len = (fl[PF_ALT_PRINT].val == 1 ? ft_strlen(s) + 1 : ft_strlen(s));
	i += pf_print_o_before(fl, len);
	i += ft_putstr(s);
	ft_strdel(&s);
	i += pf_print_o_after(fl, len);
	return (i);
}
