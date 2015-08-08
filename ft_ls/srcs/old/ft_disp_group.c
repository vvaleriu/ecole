/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 11:49:31 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/13 13:51:45 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_disp_group(char *group, int grp_l)
{
	int		a;

	ft_putstr(group);
	a = grp_l - ft_strlen(group);
	while (a)
	{
		ft_putchar(' ');
		a--;
	}
	ft_putstr("  ");
}
