/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcarray_add_first.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:22:47 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/19 09:42:10 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

/*
** On calcule le nombre de phrases, puis le nombre total de lettres.
** On recree un double pointeur avec le nombre de phrases plus 1 pour la
** nouvelle phrase plus un pour terminer le tableau
** On creer une str geaante avec le nombre de lettres + le nombre de lettes
** de l'ajout
** On copie tout ca et roulez jeunesse
*/

void		ft_strcarray_add_first(char ***ar, char *str)
{
	char	**ret;
	int		i;

	ret = NULL;
	i = 0;
	ret = (char **)ft_memalloc(sizeof(char *) * (ft_strarray_len(*ar) + 2));
	if (ret && str)
	{
		ret[0] = ft_strdup(str);
		while ((*ar)[i])
		{
			ret[i + 1] = (*ar)[i];
			i++;
		}
		free(*ar);
		*ar = ret;
	}
}
