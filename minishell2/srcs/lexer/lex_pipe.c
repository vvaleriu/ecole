/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:09:23 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/26 19:42:57 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void	lex_pipe(char **buf, t_list **alst)
{
	t_list	*tmp;

	tmp = ft_lstnew((void *)ft_strndup(*buf, 1), sizeof(char *));
	ft_lstadd_last(alst, tmp);
	(*buf)++;
}
