/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/02 17:12:15 by vincent           #+#    #+#             */
/*   Updated: 2016/03/04 12:36:05 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
**
*/

/*static int print_sel_item_s(t_tconf *conf, t_dlist *el)
{
	t_item	*item;

	item = (t_item *)el->content;
	if (item->sel == 1)
	{
		ft_putstr_fd(item->s, conf->fd);
		return (1);
	}
	return (0);
}

static void return_selected_elements(t_tconf *conf)
{
	t_dlist		*tmp;
	int			print_space;

	tmp = conf->list;
	print_space = 0;
	print_space = print_sel_item_s(conf, tmp);
	tmp = tmp->next;
	while (tmp != conf->list)
	{
		if (((t_item *)tmp->content)->sel == 1 || print_space == 1)
		{
			ft_putstr_fd(" ", conf->fd);
			print_space = 0;
		}
		print_sel_item_s(conf, tmp);
		tmp = tmp->next;
	}
	ft_putstr_fd("\n", conf->fd);
}*/

static int print_sel_item_s(t_dlist *el)
{
	t_item	*item;

	item = (t_item *)el->content;
	if (item->sel == 1)
	{
		ft_putstr(item->s);
		return (1);
	}
	return (0);
}

static void return_selected_elements(t_tconf *conf)
{
	t_dlist		*tmp;
	int			print_space;

	tmp = conf->list;
	print_space = 0;
	print_space = print_sel_item_s(tmp);
	tmp = tmp->next;
	while (tmp != conf->list)
	{
		if (((t_item *)tmp->content)->sel == 1 || print_space == 1)
		{
			ft_putstr(" ");
			print_space = 0;
		}
		print_sel_item_s(tmp);
		tmp = tmp->next;
	}
	ft_putstr("\n");
}

int			close_program(t_tconf *conf, char *key_buf)
{
	if (tcsetattr(0, TCSADRAIN, &conf->def) == -1)
	{
		ft_putendl("Error restoring default terminal capabilities.");
		exit(-1);
	}
	set_str_cap("cl:ve:te");
	close(conf->fd);
	conf->cur.c_lflag = (ICANON | ECHO | ISIG);
	if (!ft_strcmp(key_buf, "\012"))
		return_selected_elements(conf);
	exit_clean(conf);
	exit(0);
	return (-1);
}