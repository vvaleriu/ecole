/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:35:01 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:34:57 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void		ft_strarray_del(char ***ar)
{
	if (ar && **ar)
		free(**ar);
	if (*ar)
		free(*ar);
	*ar = NULL;
}
