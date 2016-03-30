/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_small.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:23:20 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/30 19:53:37 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void	lex_small(t_var *var, char **buf, t_list **alst)
{
	t_list	*tmp;

	(void *)var;
	if (buf[0][1] == '<')
	{
		tmp = ft_lstnew((void *)ft_strndup(*buf, 2), sizeof(char *));
		ft_lstadd_last(alst, tmp);
		*buf += 2;
	}
	else
	{
		tmp = ft_lstnew((void *)ft_strndup(*buf, 1), sizeof(char *));
		ft_lstadd_last(alst, tmp);
		(*buf)++;
	}
}
