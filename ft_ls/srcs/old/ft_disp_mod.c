/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 12:03:32 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/12 12:20:50 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_disp_mod(char *mod, int mod_l)
{
	int		a;

	a = mod_l - ft_strlen(mod);
	while (a)
	{
		ft_putchar(' ');
		a--;
	}
	ft_putstr(mod);
	ft_putchar(' ');
}
