/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_in_dir_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 15:11:28 by vincent           #+#    #+#             */
/*   Updated: 2015/08/08 19:30:58 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** - Receive the name of the directory as an argument
** - Returns a list of t_file structure filled with info of the files contained
** in the directory given as argument, and setup the print properties
**
** - Open the directory "opendir()"
** - Repeat reding files into the open directory "readdir"
** - For each file found, create the full patname, the send ot to get_file_info
** to reive a t_file structure and add it to the list
**
** tmp: dirent struct containing info about a file contained in dir
** file_tmp: temporary pointer on the t_file struct returned by get_file_info
*/

t_list		*get_file_in_dir_info(char *dirname, short *pp)
{
	DIR				*dir;
	t_list			*alst;
	t_dirent		*tmp;
	t_file			*file_tmp;

	dir = NULL;
	alst = NULL;
	if ((dir = opendir(dirname)))
	{
		while ((tmp = readdir(dir)) != NULL)
		{	
			//get_file_path_name(dirname, tmp->d_name);
			file_tmp = get_file_info(get_file_path_name(dirname, tmp->d_name));
			set_print_prop(file_tmp, pp);
			ft_lstadd_last(&alst, ft_lstnew(file_tmp, sizeof(t_file)));
		}
		if (closedir(dir) != 0)
			ft_putstr_fd("closedir() failed.\n", 2);
		return (alst);
	}
	return (NULL);
}