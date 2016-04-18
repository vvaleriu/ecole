/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:31:49 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 15:11:01 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		pf_print_o_before(t_pf_flag *fl, size_t len)
{
	char	filler;
	int		i;
	int		p;
	int		acc;

	i = 0;
	acc = (fl[PF_ACC].val != -1 && fl[PF_ACC].val > (int)len ? fl[PF_ACC].val\
	- len : 0);
	filler = (fl[PF_FILL_0].val == 1 && fl[PF_ACC].val == -1 ? '0' : ' ');
	p = (!fl[PF_AL_LEFT].val && fl[PF_WIDTH].val > -1 ? fl[PF_WIDTH].val -\
	len - acc : 0);
	i += pf_repeat_char(filler, p);
	i += pf_repeat_char('0', acc);
	if (fl[PF_ALT_PRINT].val)
		i += ft_putchar('0');
	return (i);
}

int		pf_print_o_after(t_pf_flag *fl, size_t len)
{
	int		i;
	int		p;

	i = 0;
	if (fl[PF_AL_LEFT].val && fl[PF_WIDTH].val > -1)
	{
		p = (fl[PF_WIDTH].val > -1 ? fl[PF_WIDTH].val - len : 0);
		i = pf_repeat_char(' ', p);
	}
	return (i);
}

int		pf_print_o(unsigned int n, t_pf_flag *fl)
{
	int		i;
	char	*s;
	int		len;

	i = 0;
	s = ((fl[PF_ACC].val != -1 && !n) || (fl[PF_ALT_PRINT].val && !n) ?\
		ft_strdup("") : ft_otoa(n));
	len = (fl[PF_ALT_PRINT].val == 1 ? ft_strlen(s) + 1 : ft_strlen(s));
	i += pf_print_o_before(fl, len);
	i += ft_putstr(s);
	ft_strdel(&s);
	i += pf_print_o_after(fl, len);
	return (i);
}
