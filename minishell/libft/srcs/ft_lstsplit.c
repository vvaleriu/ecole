/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/17 10:40:53 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

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
