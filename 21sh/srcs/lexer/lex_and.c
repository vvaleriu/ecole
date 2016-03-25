/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 10:38:11 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/24 11:31:49 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void		lex_and(char **buf, t_list **alst)
{
	t_list	*tmp;

	if (*((*buf) + 1) == '&')
	{
		tmp = ft_lstnew((void *)ft_strndup(*buf, 2), sizeof(char *));
		ft_lstadd_last(alst, tmp);
		(*buf) += 2;
	}
	else
	{
		// afficher une erreur de parsing
		(*buf)++;
	}

}