/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_group_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 13:04:38 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/06 02:04:35 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Recoit une variable gid_t contenue dans une structure stat
** Cree un malloc de la taille de la structure group (t_group).
** Va chercher l'element Groupe name de la structure group et l'affiche
*/

char	*ft_get_group_name(gid_t st_gid)
{
	t_group		*grp;

	grp = getgrgid(st_gid);
	return (grp->gr_name);
}
