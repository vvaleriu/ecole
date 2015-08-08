/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_man.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:13:15 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/15 15:13:19 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_disp_man(char *man, int man_l)
{
	int		a;

	a = man_l - ft_strlen(man);
	while (a)
	{
		ft_putchar(' ');
		a--;
	}
	ft_putstr(man);
	ft_putchar(' ');
}
