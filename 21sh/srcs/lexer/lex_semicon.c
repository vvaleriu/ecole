/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_semicon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:09:23 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/31 12:06:05 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

void	lex_semicon(t_var *var, char **buf, t_list **alst)
{
	t_list	*tmp;

	var = (void *)var;
	tmp = ft_lstnew((void *)ft_strndup(*buf, 1), sizeof(t_token));
	ft_lstadd_last(alst, tmp);
	(*buf)++;
}
