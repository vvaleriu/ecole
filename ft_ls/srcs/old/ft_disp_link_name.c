/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_link_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 17:39:14 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/12 17:51:55 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_disp_link_name(char *lk, char *filetype)
{
	if (ft_strcmp(filetype, "l") == 0)
	{
		ft_putstr(" -> ");
		ft_putstr(lk);
	}

}
