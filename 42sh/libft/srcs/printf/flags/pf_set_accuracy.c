/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_accuracy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:45:14 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 14:23:09 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		pf_set_arg_acc(t_pf_flag *flags, va_list ap)
{
	int		precision;

	precision = va_arg(ap, int);
	if (precision >= 0)
		flags[PF_ACC].val = precision;
	else
		flags[PF_ACC].val = -1;
}

void		pf_set_accuracy(t_pf_flag *flags, char **s, va_list ap)
{
	if (**s == '.')
	{
		flags[PF_ACC].val = 0;
		(*s)++;
		if (**s == '*')
		{
			pf_set_arg_acc(flags, ap);
			(*s)++;
		}
		else if (ft_isdigit(**s))
			flags[PF_ACC].val = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
}
