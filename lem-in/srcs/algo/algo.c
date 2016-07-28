/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 23:38:41 by vincent           #+#    #+#             */
/*   Updated: 2016/07/28 13:31:41 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

/*
** Rearrange le graphe en remmettant les sommets visites pour rien a 0 et en
** enlevant de ce graphes les sommets qui appartiennent au denier chemin valide
** trouve
*/
static void		reset_rooms_tag(t_lemin_var *var)
{
	int			i;

	i = -1;

	var->start->tag = 0;
	var->end->tag = 0;
	while (++i < var->room_nb && var->paths_nb)
	{
		if (!is_part_of_final_path(var->paths[var->paths_nb - 1], var->rooms)
			&& ((t_vertex *)(var->rooms->content))->tag != -1)
			((t_vertex *)(var->rooms->content))->tag = 0;
		var->rooms = var->rooms->next;
	}
}

/*
** si le nombre de souris est superieur a 1 alors on doit chercher au moins
** les deux meilleurs chemins
** retourne -1 si ne trouve aucun chemin
*/
static int		init_algo(t_lemin_var *var)
{
	int		ret;

	if (var->ant_nb == 1)
		return (width_search(var, var->start));
	if (!(ret = width_search(var, var->start)))
		return (-1);
	reset_rooms_tag(var);
	width_search(var, var->start);
	reset_rooms_tag(var);
	return (var->paths_nb);
}

/*
** On prend la longueur du moins bon chemin et on voit combien on peut faire
** transiter de fournis avant d'utliser celui la pour une seule fourmi.
** Si toutes les fourmis ont transite alors on a notre nombre de coup et on
** peut calculer la repartition
** RETOURNE -1 si auncun chemin n'a ete trouve
** Retourne 2 si on n'a qu'un seul chemin a faire
*/
static int		nb_of_necessary_turns(t_lemin_var *var)
{
	int		i;
	int		turn;
	int		ants_moved;
	int		longest_len;
	int		ret_search;

	i = -1;
	turn = 0;
	if ((ret_search = init_algo(var)) == -1)
		return (-1);
	if (!var->paths_nb || var->paths_nb == 1)
		return (1);
	ants_moved = 0;
	while (ants_moved < var->ant_nb)
	{
		ants_moved = 0;
		++turn;
		longest_len = var->paths[var->paths_nb - 1].len;
		while (++i < var->paths_nb)
			ants_moved += longest_len - var->paths[i].len + 1;
		if (ants_moved < var->ant_nb)
		{
			ret_search = width_search(var, var->start);
			reset_rooms_tag(var);
			if (!ret_search)
				return (turn);
		}
		i = -1;
	}
	return (turn);
}

int		algo(t_lemin_var *var)
{
	int		i;
	int		j;
	int		k;
	int		longest_len;
	int		ants_to_move;

	if ((longest_len = nb_of_necessary_turns(var)) == -1)
		return (-1);
	i = -1;
	j = 0;
	k = -1;
	longest_len = var->paths[var->paths_nb - 1].len;
	while (++i < var->paths_nb && j < var->ant_nb)
	{
		ants_to_move = longest_len - var->paths[i].len + 1;
		while (++k < ants_to_move && j < var->ant_nb)
		{
			var->ants[j].path = var->paths[i].start;
			j++;
		}
		k = -1;
	}
	i = 0;
	while (j < var->ant_nb)
	{
		var->ants[j].path = var->paths[i].start;
		++i;
		++j;
		if (i == var->paths_nb)
			i = 0;
	}
	return (1);
}