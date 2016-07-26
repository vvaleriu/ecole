/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/07/24 13:00:12 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static void	del_first(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = *alst;
	*alst = tmp->next;
	if (del)
		del(tmp->content, tmp->content_size);
	free(tmp);
}

void		ft_lstdelone(t_list **alst, t_list *d, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *alst;
	if (!alst || !(*alst) || !d)
		return;
	if (tmp == d)
		del_first(alst, del);
	else
	{
		while (tmp && tmp != d)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp)
		{
			prev->next = tmp->next;
			if (del)
				del(tmp->content, tmp->content_size);
			free(tmp);
		}
	}
}
