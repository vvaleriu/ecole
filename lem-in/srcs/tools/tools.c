/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 23:40:15 by vincent           #+#    #+#             */
/*   Updated: 2016/07/28 00:17:08 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

/*
** Renvoie un pointeur sur une piece en fonction de son nom
*/
t_vertex	*find_room_by_name(t_lemin_var *var, char *name)
{
	int			i;
	t_vertex	*ret;

	ret = NULL;
	i = -1;
	while (++i < var->room_nb)
	{
		ret = (t_vertex *)(var->rooms->content);
		if (!ft_strcmp(ret->n, name))
			return (ret);
		var->rooms = var->rooms->next;
	}
	return (NULL);
}

/*
** Verifie si un element de la liste principale se trouve dans la liste
** du meilleur chemin
*/
int			is_part_of_final_path(t_fpath fpath, t_dlist *el)
{
	int		i;

	i = -1;
	while (++i < fpath.len)
	{
		if (el->content == fpath.start->content)
			return (1);
		fpath.start = fpath.start->next;
	}
	return (0);
}

/*
** Permet de creer une piece
*/

t_vertex	*create_room(void)
{
	t_vertex	*room;

	if (!(room = (t_vertex *)ft_memalloc(sizeof(*room))))
		return (NULL);
	room->lk_nb = 0;
	room->lks = NULL;
	room->tag = 0;
	room->father = NULL;
	room->ant_nb = 0;
	return (room);
}