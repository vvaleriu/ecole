/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_del_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 17:00:14 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/03/05 16:31:00 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void		ft_strarray_del_one(char ***ar, int pos)
{
	int		i;
	int		j;
	char	**ret;

	i = 0;
	j = 0;
	if (*ar)
	{
		ret = (char **)ft_memalloc(sizeof(char *) * ft_strarraylen(*ar));
		while ((*ar)[j])
		{
			if (i != pos)
			{
				ret[i] = (*ar)[j];
				i++;
			}
			//else
			//	free((*ar)[j]);
			j++;
		}
		free(*ar);
		*ar = ret;
	}
}
