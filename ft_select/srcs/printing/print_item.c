/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_item.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:39:17 by vincent           #+#    #+#             */
/*   Updated: 2015/08/05 00:12:32 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** print a col of item.
** x and y have to be set up in the item properties for later use
** returns the size od the longest word to know which X_offest to start to with
** the next column
** current : current item the cursor is on
** check the state of the item to be printed, actived term caps and put them back
** at the end.
*/

size_t			print_item(t_dlist *current, t_dlist *elem, int x, int y)
{
	t_item	*item;

	if (current == elem)
		set_str_cap("us");
	item = (t_item*)elem->content;
	if (item->sel == 1)
		set_str_cap("mr");
	item->x = x;
	item->y = y;
	ft_putstr(item->s);
	set_str_cap("me");
	return (item->len);
}