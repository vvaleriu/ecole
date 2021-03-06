/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:03:21 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 14:57:06 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** filler : filler caracter in case of length option
** int p : 0 si appele avant affichage du chiffre, 1 si apres.
*/

int		pf_print_u_before(t_pf_flag *fl, size_t len, char *s)
{
	char	filler;
	int		i;
	int		p;

	i = 0;
	filler = (!fl[PF_FILL_0].val || (fl[PF_FILL_0].val && fl[PF_ACC].val >= 0)\
		? ' ' : '0');
	p = (!fl[PF_AL_LEFT].val && fl[PF_WIDTH].val > -1 ? fl[PF_WIDTH].val - len\
		: 0);
	i += pf_repeat_char(filler, p);
	if (ft_strlen(s) < len)
		i += pf_repeat_char('0', len - ft_strlen(s));
	return (i);
}

int		pf_print_u_after(t_pf_flag *fl, size_t len)
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

int		pf_print_u(unsigned int n, t_pf_flag *fl)
{
	int		i;
	char	*s;
	int		len;

	i = 0;
	s = ((fl[PF_ACC].val != -1 && !n) || (fl[PF_ALT_PRINT].val && !n) ?\
		ft_strdup("") : ft_itoa_unsign(n));
	len = (fl[PF_ACC].val > (int)ft_strlen(s) ? fl[PF_ACC].val :\
		(int)ft_strlen(s));
	i += pf_print_u_before(fl, len, s);
	i += ft_putstr(s);
	ft_strdel(&s);
	i += pf_print_u_after(fl, len);
	return (i);
}
