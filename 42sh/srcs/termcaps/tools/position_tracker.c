/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_tracker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:48:27 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:03:09 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

void		update_cur_pos(t_var *var, int movement)
{
	while (movement)
	{
		if (movement > 0)
		{
			if (CUR_POS_X + 1 == WIN_X)
			{
				CUR_POS_X = 0;
				CUR_POS_Y++;
			}
			else
				CUR_POS_X++;
			movement--;
		}
		else if (movement < 0)
		{
			if (!(CUR_POS_X))
			{
				CUR_POS_X = WIN_X - 1;
				CUR_POS_Y--;
			}
			else
				CUR_POS_X--;
			movement++;
		}
	}
}

void		update_line_pos(t_var *var, int movement)
{
	while (movement)
	{
		if (movement > 0)
		{
			LN_POS++;
			movement--;
		}
		else
		{
			LN_POS--;
			movement++;
		}
	}
}

void		update_trackers(t_var *var, int movement)
{
	update_cur_pos(var, movement);
	update_line_pos(var, movement);
}
