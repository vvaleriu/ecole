/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 01:22:25 by vincent           #+#    #+#             */
/*   Updated: 2016/07/21 21:17:28 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	store_path(t_dlist **path)
{
	ft_dlstiter(*path, print_path);
	ft_printf("\n");
	return (1);
}

int			deep_search(t_lemin_var *var, t_vertex *room, t_dlist **path)
{
	t_dlist		*added_node;
	t_vertex	*next_room;
	int			i;

	i = -1;
	// On rajoute ce maillon
	ft_dlstadd_last(path, (added_node = ft_dlstnew((void *)room, sizeof(*room))));
	if (room == var->end)
	{
		store_path(path);
		ft_dlstdelone(path, added_node, NULL);
		return (1);
	}
	room->tag = 1;
	while (++i < room->lk_nb)
	{
		next_room = (t_vertex *)(room->lks->content);
		if (next_room && !next_room->tag)
		{
			deep_search(var, next_room, path);
			//ft_dlstdelone(path, room->lks, NULL);
		}
		room->lks = room->lks->next;
	}
	room->tag = 0;
	ft_dlstdelone(path, added_node, NULL);
	return (0);
}
