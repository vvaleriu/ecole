/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:34:01 by vincent           #+#    #+#             */
/*   Updated: 2016/07/26 01:54:38 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	print_room_name(t_dlist *el)
{
	t_vertex	*room;

	if (!el)
		return;
	room = (t_vertex *)(el->content);
	ft_printf(" [%s]", room->n);
}

void	print_room_dlist(t_dlist *el)
{
	t_vertex	*room;

	if (!el)
		return;
	room = (t_vertex *)(el->content);
	ft_printf("[print_room_dlist][%s (tag: %d) (lk_nb: %d) (%d, %d)] ", room->n, room->tag, room->lk_nb, RX, RY);
	if (room->lk_nb == 0)
		ft_putendl("");
	else
	{
		ft_putstr("-- links :");
		ft_dlstiter(room->lks, print_room_name);
		ft_putendl("");
	}
}

void	print_path(t_dlist *el)
{
	t_vertex	*room;

	if (!el)
		return;
	room = (t_vertex *)(el->content);
	ft_printf("[%s]>", room->n);
}

void	print_ants(t_lemin_var *var)
{
	int		i;

	i = -1;
	while (++i < var->ant_nb)
	{
		ft_printf("[fourmi %d, chemin: %p]\n", var->ants[i].nb, var->ants[i].path);
	}
}

void	print_all_paths(t_lemin_var *var)
{
	int	j = -1;

	while (++j < var->paths_nb)
	{
		ft_printf("[chemin: %p] ", (var->paths[j]).start);
		ft_dlstiter((var->paths[j]).start, print_room_name);
		ft_putchar('\n');
	}
}