/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:29:01 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 16:10:32 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		pf_print_s_before(t_pf_flag *fl, size_t len)
{
	char	filler;
	int		i;
	int		p;

	i = 0;
	filler = (fl[PF_FILL_0].val == 1 ? '0' : ' ');
	p = (!fl[PF_AL_LEFT].val && fl[PF_WIDTH].val > -1 ?\
		fl[PF_WIDTH].val - len : 0);
	i += pf_repeat_char(filler, p);
	return (i);
}

int		pf_print_s_after(t_pf_flag *fl, size_t len)
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

int		pf_print_s(char *s, t_pf_flag *fl)
{
	int		i;
	int		len;
	char	*prt;

	i = 0;
	if (s == NULL)
		prt = ft_strndup("(null)", (fl[PF_ACC].val < 6 && fl[PF_ACC].val != -1\
			? fl[PF_ACC].val : 6));
	else if (fl[PF_ACC].val > -1 && (int)ft_strlen(s) > fl[PF_ACC].val)
		prt = ft_strndup(s, fl[PF_ACC].val);
	else
		prt = s;
	len = ft_strlen(prt);
	i += pf_print_s_before(fl, len);
	i += ft_putstr(prt);
	i += pf_print_s_after(fl, len);
	if (prt != s)
		ft_strdel(&prt);
	return (i);
}
