/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/24 12:55:02 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

/*
** alst : list que l'on veut decouper
** elem : element ou la liste doit etre decoupee (debut de l'autre liste)
** On avance tant qu'on n'est pas a l'element de separation. une fois arrive,
** on fait pointer l'element precedent vers null et on renvoir tmp = elem, comme
** debut de la nouvelle liste
*/
t_list	*ft_lstsplit(t_list *alst, t_list *elem)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = NULL;
	if (alst != NULL && elem && alst != elem)
	{
		tmp = alst;
		while (tmp != elem && tmp)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
	}
	return (tmp);
}
