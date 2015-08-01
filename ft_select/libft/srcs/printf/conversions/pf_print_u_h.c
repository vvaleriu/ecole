/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_u_h.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 14:03:21 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 14:57:18 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** filler : filler caracter in case of length option
** int p : 0 si appele avant affichage du chiffre, 1 si apres.
*/

int		pf_print_u_h(unsigned int n, t_pf_flag *fl)
{
	int		i;
	char	*s;
	int		len;

	i = 0;
	s = ft_itoa_unsign_short((unsigned short int)n);
	len = ft_strlen(s);
	i += pf_print_u_before(fl, len, s);
	i += ft_putstr(s);
	ft_strdel(&s);
	i += pf_print_u_after(fl, len);
	return (i);
}
