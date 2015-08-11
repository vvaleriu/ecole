/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 01:45:39 by vincent           #+#    #+#             */
/*   Updated: 2015/08/11 13:56:35 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Receive name of the file /directory.
** Returns a structure filled with info ready to printed
*/

static void		get_details_info(t_file *file, t_stat st, char *filename)
{
	ft_get_file_rights(file->rights, st.st_mode);
	file->xattr = ft_get_file_xattr(filename);
	file->link_nb = ft_get_link_nb(st.st_nlink);	// recoit une str malloc
	ft_strcpy(file->user, ft_get_user_name(st.st_uid));
	ft_strcpy(file->group, ft_get_group_name(st.st_gid));
	//ft_strcpy(file->size, ft_get_file_size(st.st_size));
	file->size = ft_get_file_size(st.st_size);
	file->mod = ft_get_last_mod(st.st_mtime);
	//OSX file->mod = ft_get_last_mod(st.st_mtimespec);
	file->min = ft_get_file_man(st.st_rdev);
	file->man = ft_get_file_min(st.st_rdev);
	//OSX file->td = (time_t *)ft_memdup(&(st.TVSEC), sizeof(time_t));
	file->td = (time_t *)ft_memdup(&(st.st_mtime), sizeof(time_t));
	file->lk = ft_strdup(ft_readlink(filename));
}

static void		get_file_name_only(t_file *file, char *filename)
{
	int		i;

	i = 0;
	ft_strrev(filename);
	while (filename[i] != '\0' && filename[i] != '/')
		i++;
	if (filename[i] == '\0')
	{
		ft_strrev(filename);
		file->name = filename;
	}
	else
	{
		ft_strrev(filename);
		file->name = filename + ft_strlen(filename) - i;
	}
}

t_file			*get_file_info(t_lsprop *prop, char *filename)
{
	t_file	*file;
	t_stat	st;

	file = NULL;
	if ((file = (t_file *)ft_memalloc(sizeof(*file))) && lstat(filename, &st) != -1)
	{
		get_file_name_only(file, filename);
		file->fullpath = filename;
		file->type = ft_get_file_type(st.st_mode);
	}
	if (file && OPT_L)
		get_details_info(file, st, filename);
	return (file);
}

/*
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
*/