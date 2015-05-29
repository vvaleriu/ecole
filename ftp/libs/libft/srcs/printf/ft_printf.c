/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:45:14 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 17:28:24 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>

void	pf_options_setup(t_pf_flag *flags, char **s, va_list ap)
{
	pf_set_flags(flags, s);
	pf_set_width(flags, s, ap);
	pf_set_accuracy(flags, s, ap);
	pf_set_conv_qual(flags, s);
}

void	pf_exec_print(int *i, t_pf_flag *fl, va_list ap, char **t)
{
	if (**t == 'd' || **t == 'i' || **t == 'D')
		pf_check_d(i, fl, ap, t);
	else if (**t == 'c' || **t == 'C')
		pf_check_c(i, fl, ap, t);
	else if (**t == 's' || **t == 'S')
		pf_check_s(i, fl, ap, t);
	else if (**t == 'u' || **t == 'U')
		pf_check_u(i, fl, ap, t);
	else if (**t == 'f')
		*i += pf_print_f(va_arg(ap, double), fl);
	else if (**t == 'x')
		pf_check_x(i, fl, ap);
	else if (**t == 'X')
		pf_check_x_cap(i, fl, ap);
	else if (**t == 'p')
		*i += pf_print_p((va_arg(ap, void *)), fl);
	else if (**t == 'o' || **t == 'O')
		pf_check_o(i, fl, ap, t);
	else if (**t == '%')
		*i += pf_print_purcentage(fl);
	else
		*i += pf_print_spaces(fl, t);
}

int		ft_printf(const char *str, ...)
{
	va_list			ap;
	t_pf_flag		flags[8];
	char			*t;
	int				i;

	pf_init_all_arrays(flags);
	t = (char *)str;
	i = 0;
	va_start(ap, str);
	while (*t)
	{
		if (*t != '%')
			i += ft_putchar(*t);
		else
		{
			t++;
			pf_options_setup(flags, &t, ap);
			pf_exec_print(&i, flags, ap, &t);
			pf_reset_options(flags);
		}
		t++;
	}
	va_end(ap);
	return (i);
}
