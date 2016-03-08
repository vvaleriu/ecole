/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:45:14 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/04 15:01:54 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** On recoit un pointeur sur string pour pouvoir le faire avancer dans
** la fonction
*/

int			pf_set_flags(t_pf_flag *flags, char **s)
{
	int i;
	int stop;

	i = 0;
	stop = 0;
	while (i < FLAGSNUM && !stop)
	{
		if (**s == flags[i].fl)
		{
			flags[i].val = 1;
			(*s)++;
			stop = 1;
		}
		i++;
	}
	if (i == FLAGSNUM && !stop)
		return (0);
	else
		return (pf_set_flags(flags, s));
}
