	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 06:58:37 by vincent           #+#    #+#             */
/*   Updated: 2016/07/19 14:57:40 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static	char	*sumstring(char **split, int len)
{
	char	*tmp;
	char	*ret;
	int		i;

	ret = NULL;
	i = -1;
	while (++i < len - 2)
	{
		tmp = ret;
		ret = ft_strjoin(ret, split[i]);
		ft_strdel(&tmp);
		if (i < len - 3)
		{
			tmp = ret;
			ret = ft_strjoin(ret, " ");
			ft_strdel(&tmp);
		}
	}
	return (ret);
}

static	void	get_room_coord(char **split, int len, int rcoord[2])
{
	rcoord[0] = ft_atoi(split[len - 2]);
	rcoord[1] = ft_atoi(split[len - 1]);
}

/*
** retourne 1 si la chambre a deja ete definie
*/
static	int		does_room_exist_already(t_lemin_var *var, t_vertex *room)
{
	t_dlist		*start;
	int			*coord;
	int			cont;

	start = var->rooms;
	cont = 0;
	while (start != var->rooms || cont)
	{
		cont = 0;
		if (!ft_strcmp(((t_vertex *)start->content)->n, room->n))
			return (1);
		coord = ((t_vertex *)start->content)->rcoord;
		if (coord[0] == RX && coord[1] == RY)
			return (1);
		start = start->next;
	}
	return (0);
}

static t_vertex	*create_room(void)
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

int				parse_room(t_lemin_var *var, char **split, t_parser_info *pi)
{
	int			len;
	t_vertex	*room;
	t_dlist		*el;

	len = ft_strarray_len(split);
	if (!is_room_name_correct(split[0]) && !are_rcoord_correct(split, len))
		return (0);
	if (!(room = create_room()))
		return (-1);
	room->n = sumstring(split, len);
	get_room_coord(split, len, room->rcoord);
	if (does_room_exist_already(var, room))
		return (0);
	el = ft_dlstnew((void *)room, sizeof(t_vertex));
	if (pi->is_start)
	{
		var->start = room;
		pi->is_start = 0;
		var->lstart = el;
	}
	if (pi->is_end)
	{
		var->end = room;
		pi->is_end = 0;
		var->lend = el;
	}
	ft_dlstadd_last(&(var->rooms), el);
	var->room_nb++;
	return (1);
}
