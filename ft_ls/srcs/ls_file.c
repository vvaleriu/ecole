/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 17:10:44 by vincent           #+#    #+#             */
/*   Updated: 2015/08/11 17:53:09 by vincent          ###   ########.fr       */
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

	file = (t_file *)il->content;
	if (print_title)
		ft_printf("%s:\n", file->fullpath);
	new_list = get_file_in_dir_info(prop, file->fullpath);
	ls_file(prop, &new_list, print_title);
}

/*
** - As we gonna ls another folder we reset print_prop
** - if *file doesnt refers to '.' or '..', we can print folder title
** - if option A is not activated then when can run the recursive portion on
** the folder if it's not starting by '.'
** - else, we have to check wether it's a real hidden folder or a reference to
** '.' or '..'. It it's a real folder we can then run the recursive function
*/

static void	ls_recursive(t_lsprop *prop, t_list *elem)
{
	t_file	*file;
	t_list	*new_list;

	reset_print_prop(prop->pp);
	file = (t_file *)elem->content;
	if (!is_curr_prev_folder(file))
		ft_printf("%s:\n", file->fullpath);
	if (!OPT_A && file->name[0] != '.')
	{
		new_list = get_file_in_dir_info(prop, file->fullpath);
		ls_file(prop, &new_list, HIDE_TITLE);
	}
	else
		if (!is_curr_prev_folder(file))
		{
			new_list = get_file_in_dir_info(prop, file->fullpath);
			ls_file(prop, &new_list, HIDE_TITLE);
		}
}

static void	ls_first_time(t_lsprop *prop, t_list **il, int print_title)
{
	t_list	*tmp;
	t_file	*file;

	tmp = *il;
	prop->first_time = 0;
	if (ft_lstlen(tmp) == 1)
	{
		file = (t_file *)(tmp->content);
		if (file->type != 'd')
			print_elem(prop, file);
		else
			ls_folder(prop, tmp, print_title);
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
			file = (t_file *)(tmp->content);
			if (file->type == 'd')
			{
				ft_putchar('\n');
				ls_folder(prop, tmp, SHOW_TITLE);
				if (OPT_RC)
					ls_recursive(prop, tmp);
			}
			tmp = tmp->next;
		}
	}
}

/*
** the next time we enter the function means we have to print the whole list,
** making no distinction between files and folders and eventually deal with the 
** recursive option if selected
** - Print all elements received
** - if recursive activated, go back to start of the list, and launch recursive
** function each time the we have a folder.
*/

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
			file = (t_file *)(tmp->content);
			if (file->type == 'd' && !is_curr_prev_folder(file))
			{
				ft_putchar('\n');
				ls_recursive(prop, tmp);
			}
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