/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 20:20:13 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/05 17:27:06 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ft_ls.h>

/*
** La fonction prend en parametre ar et av.
** Elle renvoit le nombre de dossiers / fichiers a lire passes en argument
*/

int		ft_count_files(int ac, char **av)
{
	static int		t[2] = {1, 0};

	while (I < ac)
	{
		J = (av[I][0] != '-' ? J + 1 : J);
		I++;
	}
	return (J);
}
