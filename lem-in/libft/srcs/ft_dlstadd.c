/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:31:05 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**	A inserer apres 'if (*alst == NULL)' si necessaire
**	new->next = NULL;
**	new->prev = NULL;
*/

void	ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	t_dlist	*tmp;

	if (*alst == NULL)
		*alst = new;
	else if ((*alst)->next == *alst)
	{
		(*alst)->next = new;
		(*alst)->prev = new;
		new->next = *alst;
		new->prev = *alst;
		*alst = new;
	}
	else
	{
		tmp = (*alst)->prev;
		tmp->next = new;
		(*alst)->prev = new;
		new->prev = tmp;
		new->next = *alst;
		*alst = new;
	}
}
