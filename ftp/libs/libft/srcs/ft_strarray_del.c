/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:35:01 by vvaleriu          #+#    #+#             */
/*   Updated: 2014/02/11 01:49:39 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void		ft_strarray_del(char ***ar)
{
	int		i;

	i = 0;
	while ((*ar)[i] != NULL)
	{
		ft_strdel(&(*ar)[i]);
		i++;
	}
	free(*ar);
	*ar = NULL;
}