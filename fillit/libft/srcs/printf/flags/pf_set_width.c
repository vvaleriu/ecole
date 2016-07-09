/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:45:14 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 14:22:20 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		pf_set_arg_width(t_pf_flag *flags, va_list ap)
{
	int		width;

	width = va_arg(ap, int);
	if (width >= 0)
		flags[PF_WIDTH].val = width;
	else
	{
		flags[PF_WIDTH].val = -width;
		flags[PF_AL_LEFT].val = 1;
	}
}

void		pf_set_width(t_pf_flag *flags, char **s, va_list ap)
{
	if (**s == '*')
	{
		pf_set_arg_width(flags, ap);
		(*s)++;
	}
	if (**s == '0')
	{
		flags[PF_FILL_0].val = 1;
		(*s)++;
	}
	if (ft_isdigit(**s))
	{
		flags[PF_WIDTH].val = ft_atoi(*s);
		(*s)++;
		while (ft_isdigit(**s))
			(*s)++;
	}
	if (**s == '*')
	{
		pf_set_arg_width(flags, ap);
		(*s)++;
	}
}
