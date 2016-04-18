/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elemdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/01/16 10:41:56 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_elemdup(t_list *elem)
{
	t_list	*dup;
	char	*dup_cont;
	char	*elem_cont;
	size_t	size_e;

	size_e = elem->content_size;
	dup = (t_list *)ft_memalloc(sizeof(t_list));
	if (!dup)
		return (NULL);
	dup_cont = (char *)dup->content;
	elem_cont = (char *)elem->content;
	while (size_e > 0)
	{
		*dup_cont = *elem_cont;
		size_e--;
		dup_cont++;
		elem_cont++;
	}
	dup->content_size = elem->content_size;
	dup->next = elem->next;
	return (dup);
}
