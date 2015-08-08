/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 11:51:45 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/13 15:35:46 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_disp_size(char *size, t_print_prop pt)
{
	int		a;

	if (pt.cb == 0)
	{
		a = pt.size_l - ft_strlen(size);
		while (a)
		{
			ft_putchar(' ');
			a--;
		}
		ft_putstr(size);
		ft_putchar(' ');
	}
	else
	{
		a = pt.min_l + pt.man_l + 1;
		while (a)
		{
			ft_putchar(' ');
			a--;
		}
		ft_putstr(size);
		ft_putchar(' ');
	}
}
