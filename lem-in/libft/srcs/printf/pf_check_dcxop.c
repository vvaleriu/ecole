/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_dcxop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 15:14:26 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 17:29:11 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>

void	pf_check_d(int *i, t_pf_flag *fl, va_list ap, char **t)
{
	if (**t == 'D' || fl[PF_CONV_QUAL].val == PF_L_CQ || fl[PF_CONV_QUAL].val\
		== PF_LL_CQ)
		*i += pf_print_d_long(va_arg(ap, long int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_H_CQ)
		*i += pf_print_d_h(va_arg(ap, int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_HH_CQ)
		*i += pf_print_d_hh(va_arg(ap, int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_J_CQ)
		*i += pf_print_d_j(va_arg(ap, long int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_Z_CQ)
		*i += pf_print_u_long(va_arg(ap, unsigned long int), fl);
	else
		*i += pf_print_d(va_arg(ap, int), fl);
}

void	pf_check_c(int *i, t_pf_flag *fl, va_list ap, char **t)
{
	if (**t == 'c' && fl[PF_CONV_QUAL].val != PF_L_CQ)
		*i += pf_print_c(va_arg(ap, int), fl);
	else if (**t == 'C' || (**t == 'c' && fl[PF_CONV_QUAL].val == PF_L_CQ))
		*i += pf_print_c_cap(va_arg(ap, int), fl);
}

void	pf_check_x(int *i, t_pf_flag *fl, va_list ap)
{
	if (fl[PF_CONV_QUAL].val == PF_L_CQ || fl[PF_CONV_QUAL].val == PF_LL_CQ)
		*i += pf_print_x_long(va_arg(ap, unsigned long int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_H_CQ)
		*i += pf_print_x_h(va_arg(ap, unsigned int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_HH_CQ)
		*i += pf_print_x_hh(va_arg(ap, unsigned int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_J_CQ)
		*i += pf_print_x_long(va_arg(ap, unsigned long int), fl);
	else
		*i += pf_print_x((va_arg(ap, unsigned int)), fl);
}

void	pf_check_o(int *i, t_pf_flag *fl, va_list ap, char **t)
{
	if (**t == 'O' || fl[PF_CONV_QUAL].val == PF_L_CQ || fl[PF_CONV_QUAL].val\
		== PF_LL_CQ)
		*i += pf_print_o_long(va_arg(ap, unsigned long int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_H_CQ)
		*i += pf_print_o_h(va_arg(ap, unsigned int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_HH_CQ)
		*i += pf_print_o_hh(va_arg(ap, unsigned int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_J_CQ)
		*i += pf_print_o_long(va_arg(ap, unsigned long int), fl);
	else
		*i += pf_print_o(va_arg(ap, unsigned int), fl);
}

void	pf_check_x_cap(int *i, t_pf_flag *fl, va_list ap)
{
	if (fl[PF_CONV_QUAL].val == PF_L_CQ || fl[PF_CONV_QUAL].val == PF_LL_CQ)
		*i += pf_print_x_cap_long(va_arg(ap, unsigned long int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_H_CQ)
		*i += pf_print_x_cap_h(va_arg(ap, unsigned int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_HH_CQ)
		*i += pf_print_x_cap_hh(va_arg(ap, unsigned int), fl);
	else if (fl[PF_CONV_QUAL].val == PF_J_CQ)
		*i += pf_print_x_cap_long(va_arg(ap, unsigned long int), fl);
	else
		*i += pf_print_x_cap((va_arg(ap, unsigned int)), fl);
}
