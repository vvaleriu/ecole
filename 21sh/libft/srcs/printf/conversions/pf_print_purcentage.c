/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_purcentage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:03:21 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 14:54:15 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** filler : filler caracter in case of length option
** int p : 0 si appele avant affichage du chiffre, 1 si apres.
*/

int		pf_print_purcentage_before(t_pf_flag *fl, size_t len)
{
	char	filler;
	int		i;
	int		p;

	i = 0;
	filler = (fl[PF_FILL_0].val == 1 ? '0' : ' ');
	p = (!fl[PF_AL_LEFT].val && fl[PF_WIDTH].val > -1 ? fl[PF_WIDTH].val - len\
		: 0);
	i += pf_repeat_char(filler, p);
	return (i);
}

int		pf_print_purcentage_after(t_pf_flag *fl, size_t len)
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

int		pf_print_purcentage(t_pf_flag *fl)
{
	int		i;

	i = 0;
	i += pf_print_purcentage_before(fl, 1);
	i += ft_putchar('%');
	i += pf_print_purcentage_after(fl, 1);
	return (i);
}
