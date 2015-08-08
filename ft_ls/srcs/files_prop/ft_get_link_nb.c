/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_link_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 16:51:43 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/11 17:34:37 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Recoit en parametre une structure nlink_t (contenue dans une structure
** stat.
** Affiche le nombre de liens symboliques d'une entites
*/

char	*ft_get_link_nb(nlink_t st_nlink)
{
	return (ft_itoa((int)st_nlink));
}
