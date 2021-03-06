/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_d_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:03:21 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 15:11:47 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** filler : filler caracter in case of length option
** int p : 0 si appele avant affichage du chiffre, 1 si apres.
*/

int		pf_print_d_long_before(t_pf_flag *fl, long int n, size_t len)
{
	char	filler;
	int		i;
	int		p;

	i = 0;
	if (fl[PF_SHOW_SIGN].val && fl[PF_FILL_0].val && n >= 0)
		i += ft_putchar('+');
	if (fl[PF_FILL_0].val && n < 0)
		i += ft_putchar('-');
	filler = (fl[PF_FILL_0].val == 1 ? '0' : ' ');
	p = (!fl[PF_AL_LEFT].val && fl[PF_WIDTH].val > -1 ? fl[PF_WIDTH].val - len\
		: 0);
	i += pf_repeat_char(filler, p);
	if (fl[PF_SHOW_SIGN].val && !fl[PF_FILL_0].val && n >= 0)
		i += ft_putchar('+');
	if (!fl[PF_FILL_0].val && n < 0)
		i += ft_putchar('-');
	return (i);
}

int		pf_print_d_long_after(t_pf_flag *fl, size_t len)
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

int		pf_print_d_long(long int n, t_pf_flag *fl)
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
