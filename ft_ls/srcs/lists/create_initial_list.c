/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_initial_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 00:36:18 by vincent           #+#    #+#             */
/*   Updated: 2015/08/09 00:56:39 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** - Receive a pointer on the start chained list of string.
** - For each filename wether it is a dir or a file, the function create a new
** chained list of t_file to later be printed
** - Returns a chained list of t_file
** /!\ Befire leaving, it cleans the list
*/

/*static int	is_directory(char *filename)
{
   struct stat statbuf;

	if (stat(filename, &statbuf) != 0)
		return 0;
	return (S_ISDIR(statbuf.st_mode));
}*/

/*static int	is_directory(char *filename)
{
	DIR		*dir;

	// strerror(errno) || perror(strerror(errno))
	dir = NULL;
	if ((dir = opendir(filename)) == NULL)
		return (0);
	return (1);
}*/

t_list		*create_initial_list(t_lsprop *prop, t_list **fnames)
{
	t_list	*list;
	t_list	*tmp;
	t_file	*file;

	list = NULL;
	tmp = *fnames;
	while (tmp)
	{
		file = get_file_info((char *)(tmp->content));
		set_print_prop(file, prop->pp);
		ft_lstadd_last(&list, ft_lstnew(file, sizeof(t_file)));
		tmp = tmp->next;
	}
	ft_lstdel(fnames, NULL);
	return (list);
}