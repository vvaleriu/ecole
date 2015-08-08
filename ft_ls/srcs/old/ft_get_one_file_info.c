/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_one_file_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:37:00 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/15 19:06:56 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Recoit une structure file_prop et la remplit en faisant appel aux
** differentes fonctions de recherches de proprietes
*/

void	ft_get_one_file_info(t_file_prop *file, char * directory)
{
	t_stat			*prop;

	prop = (t_stat *)ft_memalloc(sizeof(t_stat));
	if (prop && lstat(directory, prop) != -1)
	{
		file->filetype = ft_strdup(ft_get_file_type(prop->st_mode));
		file->rights = ft_strdup(ft_get_file_rights(prop->st_mode));
		file->xattr = ft_strdup(ft_get_file_xattr(directory));
		file->link_nb = ft_strdup(ft_get_link_nb(prop->st_nlink));
		file->user = ft_strdup(ft_get_user_name(prop->st_uid));
		file->group = ft_strdup(ft_get_group_name(prop->st_gid));
		file->size = ft_strdup(ft_get_file_size(prop->st_size));
		file->mod = ft_strdup(ft_get_last_mod(prop->st_mtimespec));
		file->min = ft_strdup(ft_get_file_man(prop->st_rdev));
		file->man = ft_strdup(ft_get_file_min(prop->st_rdev));
		file->td = (time_t *)ft_memdup(&(prop->TVSEC), sizeof(time_t));
		file->lk = ft_strdup(ft_readlink(directory));
		free(prop);
	}
}
