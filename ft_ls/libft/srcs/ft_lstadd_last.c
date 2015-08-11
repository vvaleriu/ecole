/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 10:48:46 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/11 11:13:24 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_last(t_list **alst, t_list *elem)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *alst;
	if (*alst == NULL)
		*alst = elem;
	else if (elem)
	{
		while (tmp)
		{
			last = tmp;
			tmp = tmp->next;
		}
		last->next = elem;
	}
}
