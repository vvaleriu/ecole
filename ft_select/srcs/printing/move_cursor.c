/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:03:49 by vincent           #+#    #+#             */
/*   Updated: 2016/03/04 14:43:48 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** Only checks if it down up or right arrow cause if its not one of them then if
** surely left arrow.
** returns a pointer to the elem of the list where the cursor will be set
** repeat next calculate how much time you have to go next on list to select
** the right element
*/

static t_dlist	*new_selected_item(t_tconf *conf, char arrow)
{
	int		repeat_next;

	if (arrow == DOWN_ARROW)
		return (CUR_ITM->next != NULL ? CUR_ITM->next : CUR_ITM);
	else if (arrow == UP_ARROW)
		return (CUR_ITM->prev != NULL ? CUR_ITM->prev : CUR_ITM);
	repeat_next = (conf->col > 0 ? conf->row : 0);
	if (arrow == RIGHT_ARROW)
	{
		while (repeat_next-- >= 0)
			CUR_ITM = CUR_ITM->next;
		return (CUR_ITM);
	}
	while (repeat_next-- >= 0)
		CUR_ITM = CUR_ITM->prev;
	return (CUR_ITM);
}

int			move_cursor(t_tconf *conf, char *key_buf)
{
	t_item	*item;

	CUR_ITM = (CUR_ITM == NULL ? LIST_ST : new_selected_item(conf, key_buf[2]));
	item = (t_item *)CUR_ITM->content;
	move_to(item->x, item->y);
	return (2);
}