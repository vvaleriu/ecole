/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/03 17:56:43 by vincent           #+#    #+#             */
/*   Updated: 2015/08/04 17:05:38 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** If the first item is being deleted then we move pre emtively the cursor to
** the next item;
** Returns 2 to trigger a redraw of the list
** Returns -1 if we cleard the last / only item of a list
*/

int		delete_item(t_tconf *conf, char *key_buf)
{
	move_to(0, 0);
	printf("============================ON RENTRE DANS DEL ITEM\n");
	if (CUR_ITM == LIST_ST)
		LIST_ST = LIST_ST->next;
	ft_dlstdelone(&(LIST_ST), CUR_ITM, del_list_elem);
	if (ft_strlen(key_buf) < 1000)
		ft_putstr("lol_delete");
	if (LIST_ST == NULL)
		return (-1);
	return (2);
}