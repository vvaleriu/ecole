/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/03 18:14:36 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dlist		*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*tmp;

	tmp = (t_dlist *)ft_memalloc(sizeof(t_dlist));
	if (!tmp)
		return (NULL);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		tmp->content_size = content_size;
		tmp->content = (void *)content;
	}
	tmp->next = tmp;
	tmp->prev = tmp;
	return (tmp);
}
/*
#include <libft.h>

t_dlist		*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*tmp;

	tmp = (t_dlist *)ft_memalloc(sizeof(t_dlist));
	if (!tmp)
		return (NULL);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		tmp->content_size = content_size;
		tmp->content = (void *)content;
	}
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}*/
