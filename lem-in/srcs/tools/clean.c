/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 00:57:25 by vincent           #+#    #+#             */
/*   Updated: 2016/07/28 01:34:29 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		del_links(t_dlist *el)
{
	t_vertex	*room;

	if (!el)
		return;
	room = (t_vertex *)(el->content);
	if (room->lks)
		ft_dlstdel(&(room->lks), NULL);
}

void			del_room(void *room, size_t size)
{
	t_vertex	*del;

	del = (t_vertex *)room;
	if (del && size)
		free(del);
}

static void		del_paths(t_lemin_var *var)
{
	int		i;

	i = -1;
	if (!var->paths)
		return;
	while (++i < var->paths_nb && var->paths)
		ft_dlstdel(&(var->paths[i].start), NULL);
	free(var->paths);
}

/*
** supprime la liste des liens de chaque piece
** supprime la liste de pieces
*/
int				clean(t_lemin_var **var)
{

	if (!var || !*var)
		return (0);
	ft_dlstiter((*var)->rooms, del_links);
	ft_dlstdel(&((*var)->rooms), del_room);
	del_paths(*var);
	if ((*var)->ants)
		free((*var)->ants);
	if (*var)
		free(*var);
	return (0);
}