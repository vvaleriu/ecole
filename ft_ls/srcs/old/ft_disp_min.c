/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 11:58:54 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/08 23:14:38 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_disp_min(char *min, int min_l)
{
	int		a;

	a = min_l - ft_strlen(min);
	while (a)
	{
		ft_putchar(' ');
		a--;
	}
	ft_putstr(min);
	ft_putstr(", ");
}
