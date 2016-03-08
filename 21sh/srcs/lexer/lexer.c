/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:30:32 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/13 17:51:23 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** Receive text entered
** Go through it to lex and create a list
** go through list_to_tab to create a tab from this list
*/

t_list		*lexer(char *buf, t_lexing_ft *lex)
{
	t_list	*alst;
	int		i;

	i = 0;
	alst = NULL;
	while (*buf)
	{
		if (is_operator(*buf))
		{
			while (i < 4)
			{
				if (!ft_strncmp(buf, lex[i].s, 1))
					lex[i].f(&buf, &alst);
				i++;
			}
			i = 0;
		}
		else if (is_space(*buf))
			while (is_space(*buf))
				buf++;
		else
			lex[5].f(&buf, &alst);
	}
	return (alst);
}
