/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 17:10:44 by vincent           #+#    #+#             */
/*   Updated: 2015/08/09 01:00:57 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** - Receive a list of t_file already filled.
** - Calls itself when needed.
** when facing a multiple argument command, ft_ls first prints files then
** folders
*/

static void	ls_folder(t_lsprop *prop, t_list *il, int print_title)
{
	t_file	*file;
	t_list	*new_list;

	(void)print_title;
	file = (t_file *)il->content;
	new_list = get_file_in_dir_info(file->name, prop->pp);
	ls_file(prop, &new_list, SHOW_TITLE);
}

static void	ls_recursive(t_lsprop *prop, t_list *elem)
{
	t_file	*file;
	t_list	*new_list;

	reset_print_prop(prop->pp);
	file = (t_file *)elem->content;
	new_list = get_file_in_dir_info(file->name, prop->pp);
	ls_file(prop, &new_list, SHOW_TITLE);
}

static void	ls_first_time(t_lsprop *prop, t_list **il, int print_title)
{
	t_list	*tmp;
	t_file	*file;

	tmp = *il;
	(void)print_title;
	prop->first_time = 0;
	if (ft_lstlen(tmp) == 1)
	{
		file = (t_file *)(tmp->content);
		if (file->type != 'd')
			print_elem(prop, file);
		else
			ls_folder(prop, tmp, HIDE_TITLE);
	}
	else
	{
		while (tmp != NULL)
		{
			file = (t_file *)(tmp->content);
			if (file->type != 'd')
				print_elem(prop, file);// on l'affiche avec les infos affichage deja enregistrees
			tmp = tmp->next;
		}
		tmp = *il;
		reset_print_prop(prop->pp);
		while (tmp != NULL)
		{
			if (file->type == 'd')
				ls_folder(prop, tmp, SHOW_TITLE);
			if (OPT_RC)
				ls_recursive(prop, tmp);
			tmp = tmp->next;
		}
	}
}

static void	ls_next_times(t_lsprop *prop, t_list **il, int print_title)
{
	t_list	*tmp;
	t_file	*file;

	tmp = *il;
	(void)print_title;
	while (tmp != NULL)
	{
		file = (t_file *)(tmp->content);
		print_elem(prop, file);
		tmp = tmp->next;
	}
	if (OPT_RC)
	{
		tmp = *il;
		while (tmp != NULL)
		{
			if (file->type == 'd')
				ls_recursive(prop, tmp);
			tmp = tmp->next;
		}
	}
}

void		ls_file(t_lsprop *prop, t_list **il, int print_title)
{
	if (prop->first_time == 1)
		ls_first_time(prop, il, print_title);
	else
		ls_next_times(prop, il, print_title);
	ft_lstdel(il, del_t_file_list);
}