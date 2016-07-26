/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 11:50:53 by vincent           #+#    #+#             */
/*   Updated: 2016/07/24 23:43:02 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		create_path_list(t_fpath *path, t_vertex *cur_room)
{
	t_vertex	*tmp;
	int			i;

	tmp = cur_room;
	i = 0;
	while (cur_room)
	{
		ft_dlstadd(&(path->start), ft_dlstnew((void *)cur_room, sizeof(*cur_room)));
		cur_room = cur_room->father;
		i++;
	}
	tmp->father = NULL;
	path->len = i;
}

static int		save_best_path(t_lemin_var *var, t_vertex *cur_room)
{
	t_fpath			*tmp;
	int				i;

	i = -1;
	var->paths_nb++;
	tmp = (t_fpath *)ft_memalloc(sizeof(*tmp) * var->paths_nb);
	if (!tmp)
		return (-1);
	while (++i < var->paths_nb - 1)
	{
		tmp[i].start = var->paths[i].start;
		tmp[i].len = var->paths[i].len;
	}
	if (var->paths)
		free(var->paths);
	var->paths = tmp;
	create_path_list(&(tmp[i]), cur_room);
	return (1);
}

int				width_search(t_lemin_var *var, t_vertex *room)
{
	t_list		*pile;
	t_vertex	*cur_room;
	t_vertex	*next_room;
	int			i;

	pile = NULL;
	i = -1;
	room->tag = 1;
	ft_lstadd_last(&pile, ft_lstnew((void *)room, sizeof(*room)));
	while (pile)
	{
		cur_room = (t_vertex *)(pile->content);
		while (++i < cur_room->lk_nb)
		{
			next_room = (t_vertex *)(cur_room->lks->content);
			if (!next_room->tag)
			{
				next_room->father = cur_room;
				next_room->tag = (next_room->lk_nb == 1 ? -1 : 1);
				if (next_room == var->end)
					return (save_best_path(var, next_room));
				ft_lstadd_last(&pile, ft_lstnew((void *)next_room, sizeof(*room)));
			}
			cur_room->lks = cur_room->lks->next;
		}
		i = -1;
		ft_lstdelone(&pile, pile, NULL);
	}
	return (0);
}
