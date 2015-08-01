/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:39:35 by vincent           #+#    #+#             */
/*   Updated: 2015/08/01 01:46:53 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_dlist		*build_list(char **list)
{
	t_dlist	*start;
	t_dlist	*elem;
	//t_item	*item;

	while (*list)
	{
		//item = new_item(*list);
		elem = ft_dlstnew((void*)new_item(*list), sizeof(t_item));
		ft_dlstadd_last(&start, elem);
		list++;
	}
	return (start);
}