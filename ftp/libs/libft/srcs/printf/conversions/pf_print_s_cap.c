/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_s_cap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:29:01 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/11 12:15:09 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** return the length of char to print when an accuracy is set.
*/

int		pf_s_cap_acc_len(wchar_t *s, t_pf_flag *fl)
{
	int				tmp;
	int				i;
	int				ret;
	unsigned int	c;

	tmp = 0;
	ret = 0;
	while (tmp <= fl[PF_ACC].val && *s)
	{
		ret = tmp;
		c = *s;
		if (c < 0x80)
			i = 1;
		else if (c < 0x800)
			i = 2;
		else if (c < 0x10000)
			i = 3;
		else if (c < 0x200000)
			i = 4;
		tmp += i;
		s++;
	}
	return (ret);
}

int		pf_s_cap_acc_nb(wchar_t *s, t_pf_flag *fl)
{
	int				tmp;
	int				i;
	int				ret;
	unsigned int	c;

	tmp = 0;
	ret = 0;
	while (tmp <= fl[PF_ACC].val && s)
	{
		c = *s;
		if (c < 0x80)
			i = 1;
		else if (c < 0x800)
			i = 2;
		else if (c < 0x10000)
			i = 3;
		else if (c < 0x200000)
			i = 4;
		tmp += i;
		ret = (tmp <= fl[PF_ACC].val ? ret + 1 : ret);
		s++;
	}
	return (ret);
}

int		pf_print_s_cap_before(t_pf_flag *fl, size_t len, wchar_t *s)
{
	char	filler;
	int		wd_len;
	int		i;

	i = 0;
	wd_len = (!fl[PF_AL_LEFT].val && fl[PF_WIDTH].val > -1 ? fl[PF_WIDTH].val -\
		(int)len : 0);
	filler = (fl[PF_FILL_0].val == 1 ? '0' : ' ');
	i += pf_repeat_char(filler, wd_len);
	if (fl[PF_ACC].val > 0)
	{
		wd_len = pf_s_cap_acc_nb(s, fl);
		while (wd_len && *s)
		{
			i += ft_putwchar(*s);
			wd_len--;
			s++;
		}
	}
	else
		i += ft_putwstr(s);
	return (i);
}

int		pf_print_s_cap(wchar_t *s, t_pf_flag *fl)
{
	int		i;
	int		len;
	wchar_t *prt;

	i = 0;
	if (s == NULL)
		prt = ft_wstrndup(L"(null)", fl[PF_ACC].val < 6 && fl[PF_ACC].val != -1\
			? fl[PF_ACC].val : 6);
	else if (fl[PF_ACC].val > -1 && (int)ft_wstrlen(s) > fl[PF_ACC].val)
		prt = ft_wstrndup(s, fl[PF_ACC].val);
	else
		prt = s;
	len = (fl[PF_ACC].val != -1 && fl[PF_ACC].val < (int)ft_wstrlen(prt) ?\
		pf_s_cap_acc_len(prt, fl) : (int)ft_wstrlen(prt));
	i += pf_print_s_cap_before(fl, len, prt);
	i += pf_print_s_after(fl, len);
	if (prt != s)
		ft_wstrdel(&prt);
	return (i);
}
