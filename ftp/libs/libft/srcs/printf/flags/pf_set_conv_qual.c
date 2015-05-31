/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_conv_qual.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:45:14 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 14:21:33 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** On recoit un pointeur sur string pour pouvoir le faire avancer dans
** la fonction
*/

void		pf_set_conv_qual_first(t_pf_flag *flags, char **s)
{
	if (*((*s) + 1) == 'h')
	{
		flags[PF_CONV_QUAL].val = PF_HH_CQ;
		(*s) += 2;
	}
	else
	{
		flags[PF_CONV_QUAL].val = PF_H_CQ;
		(*s)++;
	}
}

void		pf_set_conv_qual_second(t_pf_flag *flags, char **s)
{
	if (*((*s) + 1) == 'l')
	{
		flags[PF_CONV_QUAL].val = PF_LL_CQ;
		(*s) += 2;
	}
	else
	{
		flags[PF_CONV_QUAL].val = PF_L_CQ;
		(*s)++;
	}
}

void		pf_set_conv_qual(t_pf_flag *flags, char **s)
{
	if (**s == 'h')
		pf_set_conv_qual_first(flags, s);
	else if (**s == 'l')
		pf_set_conv_qual_second(flags, s);
	else if (**s == 'j')
	{
		flags[PF_CONV_QUAL].val = PF_J_CQ;
		(*s)++;
	}
	else if (**s == 'z')
	{
		flags[PF_CONV_QUAL].val = PF_J_CQ;
		(*s)++;
	}
}
