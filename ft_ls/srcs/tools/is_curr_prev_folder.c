/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_curr_prev_folder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 16:00:51 by vincent           #+#    #+#             */
/*   Updated: 2015/08/11 16:05:09 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** determines wether the cirrent file refers to current ('.') or previous ('..')
** dir
*/

short		is_curr_prev_folder(t_file *file)
{
	if (file->name[0] != '.')
		return (0);
	if (file->name[1] == '\0')
		return (1);
	if (file->name[1] == '.' && file->name[2] == '\0')
		return (1);
	return (0);
}