/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcarray_del_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 17:00:14 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/19 09:35:09 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

/*
** pos peut aller de 0 (premiere case du tableau) au nombre
** d'elements de ce tableau
*/

void		ft_strcarray_del_one(char ***ar, int pos)
{
	int		t[3];
	char	**ret;

	ret = NULL;
	J = 0;
	K = 0;
	if (pos >= 0 && pos < (I = ft_strarray_len(*ar)) && ar != NULL && *ar &&
		(ret = (char **)ft_memalloc(sizeof(char *) * I)))
	{
		while ((*ar)[J])
		{
			if (J != pos)
			{
				ret[K] = (*ar)[J];
				K++;
			}
			else
				free((*ar)[J]);
			J++;
		}
		free(*ar);
		*ar = ret;
	}
}
