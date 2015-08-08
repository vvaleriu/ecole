/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 11:28:32 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/08 01:33:39 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static int		sort_elem(t_list **alst);

void	ft_sort(t_list **alst)
{
	int		i;

	i = 0;
	if ((*alst)->next != NULL)
		while (sort_elem(alst))
			i++;
}

static int		sort_elem(t_list **alst)
{
	t_list	*t[3] = {*alst, (*alst)->next, *alst};

	if (CMP(((T_FP *)(I->CT))->name, ((T_FP *)(J->CT))->name) > 0)
	{
		I->next = J->next;
		J->next = I;
		*alst = J;
	}
	I = J;
	J = J->next;
	while (J)
	{
		if (CMP(((T_FP *)(I->CT))->name, ((T_FP *)(J->CT))->name) > 0)
		{
			I->next = J->next;
			J->next = I;
			K->next = J;
			return (1);
		}
		K = I;
		I = J;
		J = J->next;
	}
	return (0);
}
