/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:39:35 by vincent           #+#    #+#             */
/*   Updated: 2015/08/01 11:16:04 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void		pt_elem(t_dlist *elem)
{
	t_item	*item;

	item = (t_item*)elem->content;
	printf("%s [len: %zu, x: %d, y: %d, sel: %d]\n", item->s, item->len,
		item->x, item->y, item->sel);
}


void			deb_list(t_tconf *conf)
{
	ft_printf("[deb_list]\nLongueur de la liste : %u\n", ft_dlstlen(conf->list));
	ft_dlstiter(conf->list, pt_elem);
}
