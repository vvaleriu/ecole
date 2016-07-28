/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mouv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 11:39:23 by vincent           #+#    #+#             */
/*   Updated: 2016/07/28 13:28:30 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		print_mouvment(t_ant ant)
{
	ft_printf("L%d-%s ", ant.nb, ((t_vertex *)(ant.path->content))->n);
}

/*void			print_mouv(t_lemin_var *var)
{
	int			i;
	t_dlist		*path;
	int			turn;

	i = -1;
	turn = 0;
	while (var->end->ant_nb < var->ant_nb)
	{
		ft_printf("[%d]", ++turn);
		while (++i < var->ant_nb)
		{
			path = var->ants[i].path;
			if (((t_vertex *)(path->content)) != var->end && (((t_vertex *)(path->next->content) == var->end) || (((t_vertex *)(path->next->content))->ant_nb == 0)))
			{
					((t_vertex *)(path->content))->ant_nb = 0;
					((t_vertex *)(path->next->content))->ant_nb++;
					(var->ants[i]).path = (var->ants[i]).path->next;
					print_mouvment(var->ants[i]);
			}
		}
		ft_putchar('\n');
		i = -1;
	}
}*/

void			print_mouv(t_lemin_var *var)
{
	int			i;
	t_dlist		*path;
	int			turn;

	i = -1;
	turn = 0;
	while (var->end->ant_nb < var->ant_nb)
	{
		ft_printf("[%d]", ++turn);
		while (++i < var->ant_nb)
		{
			path = var->ants[i].path;
			if (((t_vertex *)(path->content)) != var->end)
			{
				if (((t_vertex *)(path->next->content) == var->end) || (((t_vertex *)(path->next->content))->ant_nb == 0))
				{
					((t_vertex *)(path->content))->ant_nb = 0;
					((t_vertex *)(path->next->content))->ant_nb++;
					(var->ants[i]).path = (var->ants[i]).path->next;
					print_mouvment(var->ants[i]);
				}
			}
		}
		ft_putchar('\n');
		i = -1;
	}
}