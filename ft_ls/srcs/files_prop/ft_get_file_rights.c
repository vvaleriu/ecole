/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_rights.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 15:16:32 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/08 01:24:58 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Recoit en parametre une structure mode_t (provenant elle meme d'une 
** structure stat)
** Interprete la valeur recu grace a une macro de sys/stat.h pour determiner
** les droits.
*/


static void		usr_rights(char *tab, mode_t st_mode)
{
	if (S_IRUSR & st_mode)
		tab[0] = 'r';
	else
		tab[0] = '-';
	if (S_IWUSR & st_mode)
		tab[1] = 'w';
	else
		tab[1] = '-';
	if (S_IXUSR & st_mode)
		tab[2] = 'x';
	else
		tab[2] = '-';
}

static void		grp_rights(char *tab, mode_t st_mode)
{
	if (S_IRGRP & st_mode)
		tab[3] = 'r';
	else
		tab[3] = '-';
	if (S_IWGRP & st_mode)
		tab[4] = 'w';
	else
		tab[4] = '-';
	if (S_IXGRP & st_mode)
		tab[5] = 'x';
	else
		tab[5] = '-';
}

static void		oth_rights(char *tab, mode_t st_mode)
{
	if (S_IROTH & st_mode)
		tab[6] = 'r';
	else
		tab[6] = '-';
	if (S_IWOTH & st_mode)
		tab[7] = 'w';
	else
		tab[7] = '-';
	if (S_IXOTH & st_mode)
		tab[8] = 'x';
	else
		tab[8] = '-';
}

void			ft_get_file_rights(char *file_rights, mode_t st_mode)
{
	usr_rights(file_rights, st_mode);
	grp_rights(file_rights, st_mode);
	oth_rights(file_rights, st_mode);
}

/*
char			*ft_get_file_rights(mode_t st_mode)
{
	char	*tab;

	tab = ft_strnew(9);
	usr_rights(tab, st_mode);
	grp_rights(tab, st_mode);
	oth_rights(tab, st_mode);
	return (tab);
}
*/
