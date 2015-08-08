/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_list_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/07 01:13:43 by vincent           #+#    #+#             */
/*   Updated: 2015/08/07 17:59:52 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

/*
** if list len is > 1, then before the list is sent to ls for the first time, it
** has to be sorted so that the files appear before the dirs
*/

void		initial_list_sort(t_list **)
{
	if (ft_lstlen(*ft_fl) > 1)
		ft_pustr("lol");
}