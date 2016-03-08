/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:39:17 by vincent           #+#    #+#             */
/*   Updated: 2016/03/04 14:42:23 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** print a col of item.
** int x_offset : X where to start the column
** longest: size of the longest word
** ROWS: numbers of row in the terminal
** list_len: list length to eventually stop before we run out of item and still
**		have col
** toprint: number of elements left to print
** returns the size od the longest word to know which X_offest to start to with
** the next column
** return -1 if a not enough space in column to print the longest word
*/

static	int		print_col(t_tconf *conf, t_dlist **list, int x_offset, int *toprint)
{
	int		ftsel[5];

	conf->row = 0;
	if (*list == NULL)
		return (-1);
	Y_OFFSET = 0;
	LONGEST = 0;
	ROWS = conf->w.ws_row;
	while (ROWS && *toprint)
	{
		if ((int)ft_strlen(((t_item*)((*list)->content))->s) >= ((int)conf->w.ws_col - x_offset))
			return (-1);
		move_to(x_offset, Y_OFFSET);
		TMP = (int)print_item(conf, *list, x_offset, Y_OFFSET);
		LONGEST = (LONGEST < TMP ? TMP : LONGEST);
		*list = (*list)->next;
		ROWS--;
		(*toprint)--;
		Y_OFFSET++;
		conf->row++;
	}
	return (LONGEST);
}

/*
** tmp : is a marker on the list sent to print_col
** offest : is set to 1 more space of the longest word from the latest column
** toprint : number of item left to print
** Launch a first draw of items. If some items are left to be drawn then we enter
** the loop until no item left. Each time we enter the loop we update the number
** of columns (conf->col) of items inside conf.
** At the end of printing, it moves the cursors to the current selected item.
**
*/

void			print_list(t_tconf *conf)
{
	t_dlist	*tmp;
	int		toprint;
	int		x_offset;
	int		print_col_ret;
	t_item	*item;

	set_str_cap("cl");
	CUR_ITM = (CUR_ITM == NULL ? LIST_ST : CUR_ITM);
	item = (t_item *)CUR_ITM->content;
	x_offset = 0;
	tmp = conf->list;
	conf->col = 1;
	toprint = ft_dlstlen(tmp);
	x_offset += print_col(conf, &tmp, x_offset, &toprint) + 1;
	while (tmp != conf->list && print_col_ret != -1)
	{
		conf->col++;
		print_col_ret = print_col(conf, &tmp, x_offset, &toprint);
		x_offset += print_col_ret + 1;
	}
	if (print_col_ret == -1)
		print_small_size_error(conf);
	move_to(item->x, item->y);
}