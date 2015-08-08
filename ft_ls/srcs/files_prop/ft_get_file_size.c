/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 17:14:35 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/08 02:02:44 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Recoit en parametre une structure off_t (contenue dans une structure
** stat.
** Affiche la taille en octects du fichier
*/

char	*ft_get_file_size(off_t st_size)
{
	return (ft_itoa((unsigned int)st_size));
}

