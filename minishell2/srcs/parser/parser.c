/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 13:27:20 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/03/06 12:50:50 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_minishell2.h>

static t_token		*return_token(t_list *list, t_list *tmp, t_list *right,\
									t_token *tk)
{
	if (ft_lstlen(list) == 1)
	{
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
		return (tk);
	}
	ft_lstsplit(list, tmp);
	right = ft_lstsplit(tmp, tmp->next);
	tk->left = parser(list);
	tk->right = parser(right);
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (tk);
}

t_token				*parser(t_list *list)
{
	t_list	*right;
	t_list	*tmp;
	t_token *tk;
	int		pty;

	right = NULL;
	tmp = list;
	pty = 0;
	if (list)
		while (pty < PTY_NB)
		{
			while (tmp)
			{
				tk = (t_token *)tmp->content;
				if (tk->pty == pty)
					return (return_token(list, tmp, right, tk));
				tmp = tmp->next;
			}
			tmp = list;
			pty++;
		}
	return (NULL);
}
