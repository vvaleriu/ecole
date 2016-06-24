/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:39:35 by vincent           #+#    #+#             */
/*   Updated: 2015/08/02 13:21:34 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	build_list(t_tconf *conf, char **list)
{
	t_dlist	*elem;

	while (*list)
	{
		elem = ft_dlstnew(new_item(*list), sizeof(t_item));
		ft_dlstadd_last(&(conf->list), elem);
		list++;
	}
}
