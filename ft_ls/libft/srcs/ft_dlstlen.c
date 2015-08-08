/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 09:24:22 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/08/03 18:14:38 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_dlstlen(t_dlist *alst)
{
	t_dlist	*tmp;
	int		i;

	i = 1;
	tmp = alst;
	if (alst == NULL)
		return (0);
	if (alst->next == alst)
		return (i);
	while (tmp->next != alst)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
