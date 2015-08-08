/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_date.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 15:14:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/15 22:55:58 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

static int		sort_elem(t_list **alst);

void	ft_sort_date(t_list **alst)
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

	if (DT(*(((T_FP *)(t[0]->CT))->td), *(((T_FP *)(t[1]->CT))->td)) < 0)
	{
		t[0]->next = t[1]->next;
		t[1]->next = t[0];
		*alst = t[1];
	}
	t[0] = t[1];
	t[1] = t[1]->next;
	while (t[1])
	{
		if (DT(*(((T_FP *)(t[0]->CT))->td), *(((T_FP *)(t[1]->CT))->td)) < 0)
		{
			t[0]->next = t[1]->next;
			t[1]->next = t[0];
			t[2]->next = t[1];
			return (1);
		}
		t[2] = t[0];
		t[0] = t[1];
		t[1] = t[1]->next;
	}
	return (0);
}
