/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 23:40:15 by vincent           #+#    #+#             */
/*   Updated: 2016/07/24 23:23:38 by vincent          ###   ########.fr       */
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
** Creer un tableau de piece a partir de la liste chainee
*/
/*int			create_room_array(t_lemin_var *var)
{
	int		i;

	i = -1;
	var->rooms = var->lstart;
	if ((var->roomsarray = (t_vertex *)ft_memalloc(sizeof(*(var->roomsarray) * var->room_nb))))
		return (0);
	while (++i < var->room_nb)
	{
		var->roomsarray[i] = var->rooms;
		var->rooms = var->rooms->next;
	}
	return (1);
}*/