/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/07/20 21:43:03 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*tmp;
	t_dlist	*swap;

	if (alst != NULL && *alst != NULL)
	{
		tmp = *alst;
		(*alst)->prev->next = NULL;
		swap = NULL;
		while (tmp)
		{
			swap = tmp->next;
			if (del)
				del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = swap;
		}
		*alst = NULL;
	}
}
