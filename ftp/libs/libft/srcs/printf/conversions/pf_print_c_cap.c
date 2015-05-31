/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_c_cap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:25:53 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 14:25:44 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** int	pf_print_c_cap_space(t_pf_flag *fl, size_t len, int p)
** filler : filler caracter in case of length option
** int p : 0 si appele avant affichage du chiffre, 1 si apres.
*/

/*
** int	pf_print_c_cap(wchar_t v, t_pf_flag *fl)
** si flag '-' alors on ecrit les espaces. On ecrit le caractere. On ecrit les
** espaces a la fin si necessaire.
*/

int			pf_print_c_cap_space(t_pf_flag *fl, size_t len, int p)
{
	char	filler;
	int		i;

	i = 0;
	filler = ' ';
	p = (fl[PF_WIDTH].val > -1 ? fl[PF_WIDTH].val - len : 0);
	i = pf_repeat_char(filler, p);
	return (i);
}

int			pf_print_c_cap(wchar_t v, t_pf_flag *fl)
{
	int		i;

	i = 0;
	if (!fl[PF_AL_LEFT].val)
		i += pf_print_c_cap_space(fl, 1, 0);
	i += ft_putwchar(v);
	if (fl[PF_AL_LEFT].val)
		i += pf_print_c_cap_space(fl, 1, 1);
	return (i);
}
