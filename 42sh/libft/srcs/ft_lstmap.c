/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:51:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2013/12/20 22:29:54 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*lst_n;
	t_list	*tmp2;
	t_list	*add;

	if (lst == NULL)
		return (NULL);
	tmp = lst;
	lst_n = f(tmp);
	lst_n->next = NULL;
	tmp2 = lst_n;
	while (tmp->next)
	{
		tmp = tmp->next;
		add = f(tmp);
		tmp2->next = add;
		tmp2 = add;
	}
	return (lst_n);
}
