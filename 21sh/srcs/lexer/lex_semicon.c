/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_semicon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:09:23 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/30 19:53:43 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void	lex_semicon(t_var *var, char **buf, t_list **alst)
{
	t_list	*tmp;

	(void *)var;
	tmp = ft_lstnew((void *)ft_strndup(*buf, 1), sizeof(t_token));
	ft_lstadd_last(alst, tmp);
	(*buf)++;
}
