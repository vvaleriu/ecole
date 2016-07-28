/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entry.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 23:23:09 by vincent           #+#    #+#             */
/*   Updated: 2016/07/28 00:42:06 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	create_ants(t_lemin_var *var)
{
	int		i;

	i = -1;
	var->ants = (t_ant *)ft_memalloc(sizeof(*(var->ants)) * var->ant_nb);
	if (!var->ants)
		return (0);
	while (++i < var->ant_nb)
		var->ants[i].nb = i + 1;
	return (1);
}

static int	can_we_proceed(t_lemin_var *var)
{
	return (var->start && var->end && var->start != var->end && var->ant_nb &&
		var->room_nb && var->start->lks && var->end->lks);
}

int			read_entry(t_lemin_var *var)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 1;
	while (ret && get_next_line(0, &line) && ft_strlen(line))
		ret = parse(var, line);
	if (!(ret = (can_we_proceed(var))))
	{
		ft_putendl("ERROR");
		return (ret);
	}
	if (!create_ants(var))
		return (0);
	return (ret);
}
