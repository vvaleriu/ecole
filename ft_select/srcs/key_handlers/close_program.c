/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/02 17:12:15 by vincent           #+#    #+#             */
/*   Updated: 2016/03/03 09:38:08 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
**
*/

static void print_sel_item_s(t_dlist *el)
{
	t_item	*item;

	item = (t_item *)el->content;
	if (item->sel == 1)
	{
		ft_putstr(item->s);
		ft_putstr(" ");
	}
}

int			close_program(t_tconf *conf, char *key_buf)
{
	if (tcsetattr(0, TCSADRAIN, &conf->def) == -1)
	{
		ft_putendl("Error restoring default terminal capabilities.");
		exit(-1);
	}
	ft_putstr("\033[?1049l");
	if (!ft_strcmp(key_buf, "\012"))
		ft_dlstiter(LIST_ST, print_sel_item_s);
	set_str_cap("ve");	
	exit_clean(conf);
	exit(0);
	return (-1);
}