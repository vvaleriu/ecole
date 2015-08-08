/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_path_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 13:40:12 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/08 19:18:22 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** Prend le repertoire en parametre et renvoie le complet du fichier
** relativement ou se trouve l'executable ft_ls
** - First copy the directory into ret, then concatenate "/" and concatenate
** filename as well
*/

char	*get_file_path_name(char *directory, char *filename)
{
	char	*ret;

	ret = ft_strnew(512);
	ft_strcpy(ret, directory);
	ft_strcat(ret, "/");
	ft_strcat(ret, filename);
	return (ret);
}
