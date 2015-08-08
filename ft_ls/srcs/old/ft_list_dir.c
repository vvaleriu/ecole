/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 17:12:09 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/15 20:04:15 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Creer une structure DIR (rep) qui va stocker le resultat d'opendir avec 
** directory passe en parametre.
** Creer une structure dirent (tmp) qui contiendra ce que renvoit readdir
** readdir s'arrete lorsqu'elle a tout lu dans le dossier
** A chaque lecture de readdir, la fonction note le nom du fichier et lance
** get_file_info pour remplir une structure contenant les informations du
** fichier.
** Elle stock la structure dans une liste chainee et renvoit un pointeur vers
** le premier element de cette liste.
*/

t_list		*ft_list_dir(char *directory, t_options opt, t_print_prop *pt)
{
	DIR				*rep;
	t_list			*alst;

	rep = NULL;
	alst = NULL;
	if ((rep = opendir(directory)))
	{
		if (!opt.a)
			ft_create_lst(rep, &alst, directory, pt);
		else
			ft_create_lst_hid(rep, &alst, directory, pt);
		if (closedir(rep) != 0)
			ft_putendl("closedir() failed");
		return (alst);
	}
	else
	{
		if (ft_create_one_file(&alst, directory, pt) == 1)
			return (alst);
	}
	return (NULL);
}

