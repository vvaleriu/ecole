/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_xattr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 12:08:55 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/08 02:01:15 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
OSX
char	ft_get_file_xattr(char *file)
{
	if (listxattr(file, NULL, 2, XATTR_NOFOLLOW) > 0)
		return ('@');
	return (' ');
}
*/

char	ft_get_file_xattr(char *file)
{
	if (listxattr(file, NULL, 2) > 0)
		return ('@');
	return (' ');
}
