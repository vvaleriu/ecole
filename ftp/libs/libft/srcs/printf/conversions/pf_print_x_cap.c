/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_x_cap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:34:55 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 15:09:43 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		pf_print_x_cap_before(t_pf_flag *fl, size_t len, unsigned int n)
{
	char	filler;
	int		i;
	int		p;
	int		acc;

	i = 0;
	acc = (fl[PF_ACC].val != -1 && fl[PF_ACC].val > (int)len ? fl[PF_ACC].val -\
		len : 0);
	filler = (!fl[PF_FILL_0].val || (fl[PF_FILL_0].val && fl[PF_ACC].val >= 0)\
		? ' ' : '0');
	p = (!fl[PF_AL_LEFT].val && fl[PF_WIDTH].val > -1 ? fl[PF_WIDTH].val - len\
		- acc : 0);
	p = (fl[PF_ALT_PRINT].val ? p - 2 : p);
	if (fl[PF_ALT_PRINT].val && fl[PF_FILL_0].val && fl[PF_ACC].val == -1 && n)
		i += ft_putstr("0X");
	i += pf_repeat_char(filler, p);
	if (fl[PF_ALT_PRINT].val && fl[PF_ACC].val >= 0 && n)
		i += ft_putstr("0X");
	i += pf_repeat_char('0', acc);
	if (fl[PF_ALT_PRINT].val && !fl[PF_FILL_0].val && fl[PF_ACC].val == -1 && n)
		i += ft_putstr("0X");
	return (i);
}

int		pf_print_x_cap(unsigned int n, t_pf_flag *fl)
{
	int		i;
	char	*s;
	int		len;

	i = 0;
	s = ((fl[PF_ACC].val == 0 && !n) ? ft_strdup("") :\
		ft_itoh_cap((long unsigned int)n));
	len = (fl[PF_ALT_PRINT].val == 1 ? ft_strlen(s) + 2 : ft_strlen(s));
	i += pf_print_x_cap_before(fl, len, n);
	i += ft_putstr(s);
	ft_strdel(&s);
	i += pf_print_x_after(fl, i);
	return (i);
}
