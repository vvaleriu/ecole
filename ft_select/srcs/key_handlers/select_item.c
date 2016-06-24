/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/02 17:12:15 by vincent           #+#    #+#             */
/*   Updated: 2016/03/03 13:21:12 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** COMMENT
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
