/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 10:38:11 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 11:41:38 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

void		lex_and(t_var *var, char **buf, t_list **alst)
{
	t_list	*tmp;

	var = (void *)var;
	if (*((*buf) + 1) == '&')
	{
		tmp = ft_lstnew((void *)ft_strndup(*buf, 2), sizeof(char *));
		ft_lstadd_last(alst, tmp);
		(*buf) += 2;
	}
	else
		(*buf)++;
}
