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

#include <ftp_server.h>

/*
** Receive text entered
** Go through it to lex and create a list
** go through list_to_tab to create a tab from this list
*/

char			**lexer(char *buf)
{
	t_list	*alst;

	alst = NULL;
	while (*buf)
	{
		if (is_space(*buf))
			lex_space(&buf);
		else
			lex_char(&buf, &alst);
	}
	return (list_to_tab(alst));
}

char			**list_to_tab(t_list *l)
{
	char	**ret;
	int		len;
	int		i;
	t_list	*tmp;

	tmp = l;
	len = ft_lstlen(l);
	i = 0;
	ret = (char **)ft_memalloc(sizeof(char *) * len + 1);
	ret[len] = NULL;
	len = 0;
	while (l)
	{
		ret[i] = (char *)l->content;
		i++;
		l = l->next;
	}
	l = tmp;
	while (tmp != NULL)
	{
		l = tmp->next;
		free(tmp);
		tmp = l;
	}
	return (ret);
}
