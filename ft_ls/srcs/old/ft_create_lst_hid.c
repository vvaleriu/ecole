/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst_hid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:51:53 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/15 15:51:55 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_create_lst_hid(DIR *rep, t_list **alst, char *dir, t_print_prop *pt)
{
	t_dirent		*tmp;
	t_file_prop		*file;
	int				a;

	while ((tmp = readdir(rep)) != NULL)
	{
		file = (t_file_prop *) ft_memalloc(sizeof(t_file_prop));
		file->name = ft_strdup(tmp->d_name);
		ft_get_file_info(file, dir);
		pt->cb = (ft_strcmp(file->filetype, "b") == 0 ? 1 : pt->cb);
		pt->cb = (ft_strcmp(file->filetype, "c") == 0 ? 1 : pt->cb);
		pt->lk_l = ((a = LEN(file->link_nb)) > pt->lk_l ? a : pt->lk_l);
		pt->usr_l = ((a = LEN(file->user)) > pt->usr_l ? a : pt->usr_l);
		pt->grp_l = ((a = LEN(file->group)) > pt->grp_l ? a : pt->grp_l);
		pt->size_l = ((a = LEN(file->size)) > pt->size_l ? a : pt->size_l);
		pt->mod_l = ((a = LEN(file->mod)) > pt->mod_l ? a : pt->mod_l);
		pt->min_l = ((a = LEN(file->min)) > pt->min_l ? a : pt->min_l);
		pt->man_l = ((a = LEN(file->man)) > pt->man_l ? a : pt->man_l);
		pt->blk = pt->blk + file->blk;
		ft_lstadd_last(alst, ft_lstnew((void *)file, sizeof(t_file_prop)));
	}
}
