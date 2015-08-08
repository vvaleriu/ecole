/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_user.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 11:44:54 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/12 14:42:04 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_disp_user(char *user, int usr_l)
{
	int		a;

	ft_putstr(user);
	a = usr_l - ft_strlen(user);
	while (a)
	{
		ft_putchar(' ');
		a--;
	}
	ft_putstr("  ");
}
