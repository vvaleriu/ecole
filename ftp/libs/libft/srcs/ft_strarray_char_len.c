/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_char_len.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 08:32:39 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:34:27 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** return 0 is no strings, returns -1 is ar == null
** returns number of strings in the array
*/

int		ft_strarray_char_len(char **ar)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (ar)
	{
		while (ar[i])
		{
			len += (ft_strlen(ar[i]));
			i++;
		}
		return (len);
	}
	return (-1);
}
