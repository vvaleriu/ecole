/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:41:49 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 15:11:15 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** filler : filler caracter in case of length option
** int p : 0 si appele avant affichage du chiffre, 1 si apres.
*/

int			pf_print_f_before(t_pf_flag *fl, float n, size_t len)
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

int			pf_print_f_after(t_pf_flag *fl, size_t len)
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

char		*pf_print_precision(float f, t_pf_flag *fl)
{
	char	*s;
	int		i;

	i = 0;
	s = ft_ftoa((float)f);
	if (fl[PF_ACC].val == 0)
	{
		while (s[i] != '.')
			i++;
		s[i] = '\0';
	}
	if (fl[PF_ACC].val >= 0)
	{
		while (s[i] != '.')
			i++;
		while (s[i] && fl[PF_ACC].val > -1)
		{
			i++;
			fl[PF_ACC].val--;
		}
		s[i] = '\0';
	}
	return (s);
}

int			pf_print_f(double f, t_pf_flag *fl)
{
	int		i;
	char	*s;
	int		len;

	i = 0;
	s = pf_print_precision((float)f, fl);
	len = (f >= 0 && fl[PF_SHOW_SIGN].val == 1 ? ft_strlen(s) + 1 :\
		ft_strlen(s));
	i += pf_print_f_before(fl, (float)f, len);
	if (f < 0)
		i += ft_putstr(s + 1);
	else
		i += ft_putstr(s);
	ft_strdel(&s);
	i += pf_print_f_after(fl, len);
	return (i);
}
