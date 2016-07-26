/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:38:36 by vincent           #+#    #+#             */
/*   Updated: 2016/07/24 23:51:25 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_lemin_var		*init()
{
	t_lemin_var	*ret;

	ret = (t_lemin_var *)ft_memalloc(sizeof(*ret));
	if (!ret)
	{
		ft_printf("INIT MALLOC ERROR");
		return (ret);
	}
	ret->ant_nb = 0;
	ret->room_nb = 0;
	ret->rooms = NULL;
	ret->start = NULL;
	ret->end = NULL;
	ret->paths = NULL;
	ret->paths_nb = 0;
	ret->ants = NULL;
	return (ret);
}