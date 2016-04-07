/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_del_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 17:00:14 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:40:20 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

/*
** pos peut aller de 0 (premiere case du tableau) au nombre
** d'elements de ce tableau
*/

static int	ct_w(char **ar, int pos)
{
	return (ft_strarray_char_len(ar) - ft_strlen(ar[pos])
			+ ft_strarray_len(ar) - 1);
}

void		ft_strarray_del_one(char ***ar, int pos)
{
	int		t[3];
	char	**ret;
	char	*s;

	ret = NULL;
	s = NULL;
	J = -1;
	K = 0;
	if (pos >= 0 && pos < (I = ft_strarray_len(*ar)) && ar != NULL && *ar &&
		(ret = (char **)ft_memalloc(sizeof(char *) * I)) &&
		(s = (char *)ft_memalloc(sizeof(char) * ct_w(*ar, pos))))
	{
		while (++J && (*ar)[J])
		{
			if (J != pos)
			{
				ret[K] = s;
				ft_strcpy(s, (*ar)[J]);
				s += ft_strlen(ret[K]) + 1;
				K++;
			}
		}
		ft_strarray_del(ar);
		*ar = ret;
	}
}
