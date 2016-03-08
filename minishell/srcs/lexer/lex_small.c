/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_small.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:23:20 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/26 19:42:42 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void	lex_small(char **buf, t_list **alst)
{
	t_list	*tmp;

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
