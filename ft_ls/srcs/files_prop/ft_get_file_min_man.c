/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_min_man.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 15:41:12 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/11 17:13:09 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
**
**
**
*/

char	*ft_get_file_min(dev_t st_rdev)
{
	int		min;

	min = minor(st_rdev);
	return (ft_itoa(min));
}

char	*ft_get_file_man(dev_t st_rdev)
{
	int		man;

	man = major(st_rdev);
	return (ft_itoa(man));
}
