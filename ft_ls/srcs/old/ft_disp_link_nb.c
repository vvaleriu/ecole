/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_link_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 11:33:05 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/15 15:12:41 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_disp_link_nb(char *link_nb, int lk_l)
{
	int		a;

	a = lk_l - ft_strlen(link_nb);
	while (a)
	{
		ft_putchar(' ');
		a--;
	}
	ft_putstr(link_nb);
	ft_putchar(' ');
}
