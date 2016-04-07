/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:43:03 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 11:42:00 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

void		lex_aggregation(char **buf, t_list **alst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (buf[0][i] && ft_isdigit(buf[0][i]))
		i++;
	i++;
	while (buf[0][i] && !is_space(buf[0][i]))
		i++;
	tmp = ft_lstnew((void *)ft_strndup(*buf, i), sizeof(char *));
	*buf += i;
	ft_lstadd_last(alst, tmp);
}

/*
** On recoit une position dans la commande.
** On lance la fonction de recherche d'aggregation de sorties
*/

void		lex_alnum(char **buf, t_list **alst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (is_text(buf[0][i]) && buf[0][i])
		i++;
	tmp = ft_lstnew((void *)ft_strndup(*buf, i), sizeof(char *));
	*buf += i;
	ft_lstadd_last(alst, tmp);
}

/*
** Si le caractere est une guillement, on applique un traitement special
** Sinon, on traite le caractere normalement
*/

void		lex_char(t_var *var, char **buf, t_list **alst)
{
	if (**buf == '\"' || **buf == '\'' || **buf == '`')
		lex_quote(var, buf, alst);
	else if (is_fd_aggregation(*buf))
		lex_aggregation(buf, alst);
	else
		lex_alnum(buf, alst);
}
