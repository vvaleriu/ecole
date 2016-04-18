/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_fd_aggregation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:22:18 by vincent           #+#    #+#             */
/*   Updated: 2016/04/07 11:46:30 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

/*
** Elle verifie si on a ce patron : "N>x" avec N un nombre, le caractere
** '>' et x une chaine de caracteres
** Dans ce cas il s'agit d'une redirection et on la traite comme il se
** doit
*/

int		is_fd_aggregation(char *str)
{
	int		i;

	i = 0;
	if (*str && *str != '"' && *str != '\'')
	{
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == '>')
		{
			if (str[i + 1] == '>')
				return (0);
			return (1);
		}
	}
	return (0);
}
