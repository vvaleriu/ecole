/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/16 18:45:14 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/10 16:17:51 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**		CREATE THE FLAGS ARRAY
*/

void	pf_init_all_arrays(t_pf_flag *flags)
{
	flags[0].fl = '#';
	flags[1].fl = '-';
	flags[2].fl = '0';
	flags[3].fl = '+';
	flags[4].fl = ' ';
	flags[5].fl = 'W';
	flags[6].fl = '.';
	flags[7].fl = 'T';
	flags[0].val = 0;
	flags[1].val = 0;
	flags[2].val = 0;
	flags[3].val = 0;
	flags[4].val = 0;
	flags[5].val = -1;
	flags[6].val = -1;
	flags[7].val = 0;
}

void	pf_reset_options(t_pf_flag *flags)
{
	flags[0].val = 0;
	flags[1].val = 0;
	flags[2].val = 0;
	flags[3].val = 0;
	flags[4].val = 0;
	flags[5].val = -1;
	flags[6].val = -1;
	flags[7].val = 0;
}
