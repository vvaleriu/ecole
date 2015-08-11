/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:58:00 by vincent           #+#    #+#             */
/*   Updated: 2015/08/11 15:48:55 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** - init
** - create_filenames_list: create a list composed by the name of the files / dir
** to run ft_ls on
** - create_list: create of list of t_file struct of the files / dir contained
** into fnames_list
** - ls_file on the t_file structure list
**
** prop: contains all pro prop and structs
** fnames_list: list of files/dir passed as arguments
** prop.il: list of t_file struct containing details on files
*/

/*static void print_option(t_lsprop *prop)
{
	ft_printf("OPT_A: %d\n", OPT_A);
	ft_printf("OPT_L: %d\n", OPT_L);
	ft_printf("OPT_R: %d\n", OPT_R);
	ft_printf("OPT_RC: %d\n", OPT_RC);
	ft_printf("OPT_T: %d\n", OPT_T);
}*/

int				main(int ac, char **av)
{
	t_lsprop		prop;
	t_list			*fnames_list;

	E(-1, init(&prop, ac, av), ERR_ILL_OPT, FORCE_EXIT);
	if (!(fnames_list = create_filenames_list(ac, av)))
		fnames_list = ft_lstnew(".", sizeof(char *));
	prop.il = create_initial_list(&prop, &fnames_list);
	//first_list_sort(&(prop.il));
	/*ls_file(&prop, &(prop.il),
		(ft_lstlen(prop.il) && prop.opt[VAL_OPT_RC] > 1 ? SHOW_TITLE : HIDE_TITLE));*/
	ls_file(&prop, &(prop.il),
		(prop.opt[VAL_OPT_RC] ? SHOW_TITLE : HIDE_TITLE));
	return (0);
}
