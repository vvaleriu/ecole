/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:32:05 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static void	del_first_el(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist		*tmp;

	tmp = *alst;
	if (tmp != tmp->next)
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

void		ft_dlstdelone(t_dlist **a, t_dlist *d, void (*del)(void *, size_t))
{
	t_dlist		*tmp;

	if (a != NULL && *a != NULL && d != NULL && del != NULL)
	{
		tmp = *a;
		while (tmp != d)
			tmp = tmp->next;
		if (tmp == *a)
			del_first_el(a, del);
		else
		{
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
		}
	}
}
