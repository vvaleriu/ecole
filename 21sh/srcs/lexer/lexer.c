/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:30:32 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/30 22:55:15 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** Receive text entered
** Go through it to lex and create a list
** go through list_to_tab to create a tab from this list
** 6
*/

t_list		*lexer(t_var *var, char *buf, t_lexing_ft *lex)
{
	t_list	*alst;
	int		i;

	i = 0;
	alst = NULL;
	var->list = alst;
	while (*buf)
	{
		if (is_operator(*buf))
		{
			while (i < 5)
			{
				if (!ft_strncmp(buf, lex[i].s, 1))
					lex[i].f(var, &buf, &alst);
				i++;
			}
			i = 0;
		}
		else if (is_space(*buf))
			while (is_space(*buf))
				buf++;
		else
			lex[LEX_CHAR_NB].f(var, &buf, &alst);
	}
	return (alst);
}
