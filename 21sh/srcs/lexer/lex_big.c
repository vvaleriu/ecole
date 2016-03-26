/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_big.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:27:42 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/26 07:53:16 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** Si le caractere suivant est un ">" alors on a ">>", sinon on a simplement ">"
*/
void	lex_big(char **buf, t_list **alst)
{
	t_list	*tmp;

	if (buf[0][1] == '>')
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
