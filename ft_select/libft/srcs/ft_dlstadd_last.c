/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 10:48:46 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/01 23:32:21 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_dlstadd_last(t_dlist **alst, t_dlist *new)
{
	t_dlist	*tmp;

	if (*alst == NULL)
		*alst = new;
	else if ((*alst)->next == NULL)
	{
		(*alst)->next = new;
		(*alst)->prev = new;
		new->next = *alst;
		new->prev = *alst;
	}
	else
	{
		tmp = (*alst)->prev;
		tmp->next = new;
		(*alst)->prev = new;
		new->prev = tmp;
		new->next = *alst;
	}
}
