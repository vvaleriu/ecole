/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_item.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:39:17 by vincent           #+#    #+#             */
/*   Updated: 2015/08/02 00:36:23 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** print a col of item.
** x and y have to be set up in the item properties for later use
** returns the size od the longest word to know which X_offest to start to with
** the next column
*/

size_t			print_item(t_dlist *elem, int x, int y)
{
	t_item	*item;

	item = (t_item*)elem->content;
	item->x = x;
	item->y = y;
	ft_putstr(item->s);
	return (item->len);
}