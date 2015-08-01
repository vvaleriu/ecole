/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 17:52:36 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/18 18:05:58 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_minishell2.h>

void		free_all_list(t_list *list)
{
	t_list *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
