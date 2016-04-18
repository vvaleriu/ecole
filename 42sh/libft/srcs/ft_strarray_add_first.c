/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_add_first.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 12:22:47 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:35:26 by vvaleriu         ###   ########.fr       */
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

static int	ct_w(char **ar, char *s)
{
	return (ft_strlen(s) + ft_strarray_char_len(ar) + ft_strarray_len(ar) + 1);
}

void		ft_strarray_add_first(char ***ar, char *str)
{
	char	**ret;
	char	*s;
	int		i;

	ret = NULL;
	i = 0;
	ret = (char **)ft_memalloc(sizeof(char *) * (ft_strarray_len(*ar) + 2));
	s = (char *)ft_memalloc(sizeof(char) * ct_w(*ar, str));
	if (ret && s && str)
	{
		ret[0] = s;
		while (*str)
			*s++ = *str++;
		*s++ = '\0';
		while ((*ar)[i])
		{
			ret[i + 1] = s;
			ft_strcpy(s, (*ar)[i]);
			s += ft_strlen(ret[i + 1]) + 1;
			i++;
		}
		ft_strarray_del(ar);
		*ar = ret;
	}
}
