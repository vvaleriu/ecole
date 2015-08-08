/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_one_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 12:33:47 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/15 19:18:05 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static char		*ft_get_name(char *directory);

int		ft_create_one_file(t_list **alst, char *directory, t_print_prop *pt)
{
	char			*s;
	t_file_prop		*file;
	int				a;

	s = ft_get_name(directory);
	file = (t_file_prop *) ft_memalloc(sizeof(t_file_prop));
	ft_get_one_file_info(file, directory);
	if (!file->filetype)
		return (0);
	file->name = ft_strdup(s);
	pt->cb = (ft_strcmp(file->filetype, "c") == 0 ? 1 : pt->cb);
	pt->cb = (ft_strcmp(file->filetype, "b") == 0 ? 1 : pt->cb);
	pt->lk_l = ((a = ft_strlen(file->link_nb)) > pt->lk_l ? a : pt->lk_l);
	pt->usr_l = ((a = ft_strlen(file->user)) > pt->usr_l ? a : pt->usr_l);
	pt->grp_l = ((a = ft_strlen(file->group)) > pt->grp_l ? a : pt->grp_l);
	pt->size_l = ((a = ft_strlen(file->size)) > pt->size_l ? a : pt->size_l);
	pt->mod_l = ((a = ft_strlen(file->mod)) > pt->mod_l ? a : pt->mod_l);
	pt->min_l = ((a = ft_strlen(file->min)) > pt->min_l ? a : pt->min_l);
	pt->man_l = ((a = ft_strlen(file->man)) > pt->man_l ? a : pt->man_l);
	ft_lstadd_last(alst, ft_lstnew((void *)file, sizeof(t_file_prop)));
	return (1);
}

static char		*ft_get_name(char *directory)
{
	if (ft_strrchr(directory, '/') == NULL)
		return (directory);
	else
		return (ft_strrchr(directory, '/') + 1);
}
