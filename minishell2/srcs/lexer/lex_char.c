/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 17:43:03 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/26 19:55:36 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

void		print_missing_quote(char **buf, char *s, char qt, t_list **alst)
{
	char	*copy;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(s - 1);
	ft_printf("%s>", qt == '\'' ? "quote" : "dquote");
	get_next_line(0, buf);
	copy = ft_strjoin(tmp, "\n");
	ft_strdel(&tmp);
	*buf = ft_strjoin(copy, *buf);
	ft_strdel(&copy);
	copy = *buf + 1;
	while (*buf[i] && *buf[i] != qt)
		i++;
	if (!*buf[i])
		print_missing_quote(buf, copy, qt, alst);
	else
		lex_quote(buf, alst);
}

void		lex_quote(char **buf, t_list **alst)
{
	char	quote;
	char	*s;
	t_list	*tmp;
	int		i;

	i = 0;
	quote = **buf;
	s = ((*buf)++ ? *buf : NULL);
	while (*(*buf + i) && *(*buf + i) != quote)
		i++;
	if (!*(*buf + i))
		print_missing_quote(buf, s, quote, alst);
	else
	{
		tmp = ((*(*buf + i) == quote) && (i >= 0) ? \
			ft_lstnew((void *)ft_strndup(s, i), sizeof(char *)) : NULL);
		while (*(*buf + i) != quote)
			i++;
		i++;
		*buf += i;
		ft_lstadd_last(alst, tmp);
	}
}

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

void		lex_char(char **buf, t_list **alst)
{
	if (**buf == '\"' || **buf == '\'')
		lex_quote(buf, alst);
	else
		lex_alnum(buf, alst);
}