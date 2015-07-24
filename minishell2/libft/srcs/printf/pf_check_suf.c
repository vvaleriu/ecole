/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_suf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 15:15:29 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 17:24:30 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	pf_check_s(int *i, t_pf_flag *fl, va_list ap, char **t)
{
	if (**t == 'S' || fl[PF_CONV_QUAL].val == PF_L_CQ || fl[PF_CONV_QUAL].val\
		== PF_LL_CQ)
		*i += pf_print_s_cap(va_arg(ap, wchar_t *), fl);
	else
		*i += pf_print_s(va_arg(ap, char *), fl);
}

void	pf_check_u(int *i, t_pf_flag *fl, va_list ap, char **t)
{
	if (**t == 'U' || fl[PF_CONV_QUAL].val == PF_L_CQ || fl[PF_CONV_QUAL].val\
		== PF_LL_CQ)
		*i += pf_print_u_long(va_arg(ap, unsigned long int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_J_CQ)
		*i += pf_print_u_long(va_arg(ap, unsigned long int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_H_CQ)
		*i += pf_print_u_h(va_arg(ap, unsigned int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_HH_CQ)
		*i += pf_print_u_hh(va_arg(ap, unsigned int), fl);
	else
		*i += pf_print_u((va_arg(ap, unsigned int)), fl);
}
