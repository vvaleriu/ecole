/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:24:51 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/08 01:22:21 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Recoit une structure mode_t en parametre (elle meme contenue dans une
** structure stat).
** Va chercher les informations relatives au mode et les affiche.
*/

char	ft_get_file_type(mode_t st_mode)
{
	if (S_ISREG(st_mode))
		return ('-');
	if (S_ISFIFO(st_mode))
		return ('p');
	if (S_ISCHR(st_mode))
		return ('c');
	if (S_ISBLK(st_mode))
		return ('b');
	if (S_ISDIR(st_mode))
		return ('d');
	if (S_ISLNK(st_mode))
		return ('l');
	if (S_ISSOCK(st_mode))
		return ('s');
	else
	{
		perror(strerror(errno));
		return(' ');
	}
}
