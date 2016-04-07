/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:30:32 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 10:34:35 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** Receive text entered
** Go through it to lex and create a list
** go through list_to_tab to create a tab from this list
** 6
*/

t_list		*lexer(t_var *var, t_lexing_ft *lex)
{
	int		i;

	i = 0;
	while (*(LN_S))
	{
		if (is_operator(*(LN_S)))
		{
			while (i < 5)
			{
				if (!ft_strncmp((LN_S), lex[i].s, 1))
					lex[i].f(var, &(LN_S), &(var->list));
				i++;
			}
			i = 0;
		}
		else if (is_space(*(LN_S)))
			while (is_space(*(LN_S)))
				(LN_S)++;
		else
			lex[LEX_CHAR_NB].f(var, &(LN_S), &(var->list));
	}
	return (var->list);
}
