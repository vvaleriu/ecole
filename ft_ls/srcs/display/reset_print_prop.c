/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_print_prop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 17:02:48 by vincent           #+#    #+#             */
/*   Updated: 2015/08/08 19:26:13 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** after a display has been done and ls starts another display group, print_prop
** have to be reset to calculate right sizes
*/

void		reset_print_prop(short *pp)
{
	int		i;

	i = 0;
	while (i < PRINT_PROP_NB)
		pp[i++] = 0;
}