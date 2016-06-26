/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_list_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/01 01:39:35 by vincent           #+#    #+#             */
/*   Updated: 2015/08/02 13:21:46 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** function sent to :
**	void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
** that will iterate a delete on each element on the whole list
*/

#include <ft_select.h>

void	del_list_elem(void *content, size_t size)
{
	if (content != NULL)
		free((t_item *)content);
	content = NULL;
	if (content != NULL)
		ft_putnbr((int)size);
}
