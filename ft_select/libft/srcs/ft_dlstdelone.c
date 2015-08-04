/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/04 16:56:27 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>


static void	del_first_el(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist		*tmp;

	tmp = *alst;
	if (tmp != tmp->next)// si *alst n'est pas le seul dans la liste
	{
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		*alst = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
	}
	else
	{
		del(tmp->content, tmp->content_size);
		free(tmp);
		*alst = NULL;
	}
}

void		ft_dlstdelone(t_dlist **alst, t_dlist *d, void (*del)(void *, size_t))
{
	t_dlist		*tmp;

	if (alst != NULL && *alst != NULL && d != NULL && del != NULL)
	{
		tmp = *alst;
		while (tmp != d)
			tmp = tmp->next;
		if (tmp == *alst)
			del_first_el(alst, del);
		else
		{
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
		}
	}
}
