/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 08:32:39 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:33:45 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_putstr_array(char **ar)
{
	int	i;

	i = 0;
	while (ar && ar[i] != '\0')
	{
		ft_putendl(ar[i]);
		i++;
	}
}
