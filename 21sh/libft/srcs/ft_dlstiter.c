/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/03 18:15:47 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem))
{
	t_dlist	*tmp;

	tmp = lst;
	if (tmp != NULL)
	{
		f(tmp);
		tmp = tmp->next;
		while (tmp != lst)
		{
			f(tmp);
			tmp = tmp->next;
		}
	}
}
