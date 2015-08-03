/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/03 19:43:56 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist		*prev;
	t_dlist		*next;

	if (alst && *alst != NULL && del != NULL)
	{
		if ((*alst)->next != *alst)
		{
			next = (*alst)->next;
			prev = (*alst)->prev;
			next->prev = prev;
			prev->next = next;
		}
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}
