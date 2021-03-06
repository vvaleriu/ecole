/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 16:14:23 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 15:10:17 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** filler : filler caracter in case of length option
** int p : 0 si appele avant affichage du chiffre, 1 si apres.
*/

int			pf_print_p_before(t_pf_flag *fl, size_t len)
{
	char	filler;
	int		i;
	int		p;
	int		acc;

	i = 0;
	if (fl[PF_FILL_0].val && fl[PF_ACC].val == -1)
		i += ft_putstr("0x");
	acc = (fl[PF_ACC].val != -1 && fl[PF_ACC].val > (int)len ? fl[PF_ACC].val -\
		len : 0);
	filler = (!fl[PF_FILL_0].val || (fl[PF_FILL_0].val && fl[PF_ACC].val >= 0)\
		? ' ' : '0');
	p = (!fl[PF_AL_LEFT].val && fl[PF_WIDTH].val > -1 ? fl[PF_WIDTH].val - len\
		- acc - 2 : 0);
	i += pf_repeat_char(filler, p);
	if (fl[PF_ACC].val >= 0)
		i += ft_putstr("0x");
	i += pf_repeat_char('0', acc);
	if (!fl[PF_FILL_0].val && fl[PF_ACC].val == -1)
		i += ft_putstr("0x");
	return (i);
}

int			pf_print_p_after(t_pf_flag *fl, size_t len)
{
	int		i;
	int		p;

	i = 0;
	if (fl[PF_AL_LEFT].val && fl[PF_WIDTH].val > -1)
	{
		p = (fl[PF_WIDTH].val > -1 ? fl[PF_WIDTH].val - len : 0);
		i = pf_repeat_char(' ', p - 2);
	}
	return (i);
}

int			pf_print_p(void *ptr, t_pf_flag *fl)
{
	int		i;
	char	*s;
	int		len;

	i = 0;
	s = (!ptr ? ft_strdup("0") : ft_itoh_long((long long int)ptr));
	if (!ptr && fl[PF_ACC].val == 0)
	{
		ft_strdel(&s);
		s = ft_strdup("");
	}
	len = ft_strlen(s);
	i += pf_print_p_before(fl, len);
	i += ft_putstr(s);
	ft_strdel(&s);
	i += pf_print_p_after(fl, len);
	return (i);
}
