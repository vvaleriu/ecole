/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/02 17:12:15 by vincent           #+#    #+#             */
/*   Updated: 2015/08/05 00:12:28 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
**
*/

int			select_item(t_tconf *conf, char *key_buf)
{
	t_item	*item;

	item = (t_item*)CUR_ITM->content;
	item->sel = (item->sel == 0 ? 1 : 0);
	CUR_ITM = CUR_ITM->next;
	return (2);
	if (ft_strlen(key_buf) > 1000)
		ft_putstr("lol_close");
}