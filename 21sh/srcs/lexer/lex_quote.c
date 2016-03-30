/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 16:53:08 by vincent           #+#    #+#             */
/*   Updated: 2016/03/30 23:29:12 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** retourne 0 si n'a pas trouve la quote fermante
** retourn 1 si c'est bon
*/
int 		check_for_closing_quote(t_var *var, char **buf, char **tmp, t_list **alst)
{
	// si c'est bien ferme,
	int		i;
	char	*del;

	i = 0;
	while (LN_S[i] && LN_S[i] != LN_QUOTE)
		i++;
	if (!LN_S[i])
		return (0);
	PROMPT_LEN = PROMPT_LEN_VALUE;
	i++;
	del = *tmp;
	*tmp = ft_strjoin(*tmp, "\n");
	ft_strdel(&del);
	*buf = ft_strjoin(copy, *buf);
	ft_strdel(&copy);
	copy = *buf + 1;
	while (*buf[i] && *buf[i] != qt)
		i++;
	if (!*buf[i])
		missing_quote_loop(buf, copy, qt, alst);
	else
		lex_quote(buf, alst);
}

/*
** buf : pointeur sur la position sur laquelle on se trouve de la ligne du
** terminal
** s : ligne du terinal a l'endroit ou on repere la quote
** tmp : partie ligne que l'on a deja enregistree
** - on si on ne trouve pas de quote fermante, alors on reboucle sur la fonction
** 	affichant le prompteur pour fermer la quote
**	- Si on ne l'a pas trouvee, alors on rentre dans missing_quote_loop
**	- Sinon on continue le lexing classique
*/
void		missing_quote_loop(t_var *var, char **buf, char *s, t_list **alst)
{
	char			*copy;
	static char		*tmp = NULL;
	static char		*del = NULL;
	int				i;

	if (tmp != NULL)
		check_for_closing_quote(var, buf, &tmp, alst);
	else
	{
		del = tmp;
		tmp = ft_strjoin(tmp, s) //ft_strdup(s - 1);
		ft_strdel(&del);
		ft_strdel(&(LN_TMP));
		set_str_cap("sc");
		terminal_execute_mode(var->conf);
		if (LN_QUOTE == '\'' && (PROMPT_LEN = ft_strlen("quote>")))
			ft_printf("quote>");
		else if (LN_QUOTE == '\"' && (PROMPT_LEN = ft_strlen("dquote>")))
			ft_printf("dquote>");
		else if (LN_QUOTE == '`'  && (PROMPT_LEN = ft_strlen("bquote>")))
			ft_printf("bquote>");
		terminal_input_mode(var->conf);
		read_key(var);
	}
}
/*void		print_missing_quote(char **buf, char *s, char qt, t_list **alst)
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
}*/

/*
** quote : type de quote : " ou '
** On repere le type de quote, On avance jusqu'a ce qu'on trouve la meme sinon
** on lance print missing quote
** On garde les guillements dans la chaine trouvee pour eviter des bug d'
** interpretation du parser
*/
/*void		lex_quote(char **buf, t_list **alst)
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
}*/

/*
** s : ligne du terinal a l'endroit ou on repere la quote
** tmp : element que l'on va ajouter a la liste
** - On avance tant qu'on ne trouve pas la quote fermante
**	- Si on ne l'a pas trouvee, alors on rentre dans missing_quote_loop et on sauvegarde
**	  le ponteur sur l'espace memoire de la ligne
**	- Sinon on continue le lexing classique
*/
void		lex_quote(t_var *var, char **buf, t_list **alst)
{
	char	*s;
	t_list	*tmp;
	int		i;

	i = 1;
	LN_QUOTE = **buf;
	s = *buf;
	while (*(*buf + i) && *(*buf + i) != LN_QUOTE)
		i++;
	if (!*(*buf + i))
	{
		LN_TMP = LN_S;
		missing_quote_loop(var, buf, s, alst);
	}
	else
	{
		tmp = ((*(*buf + i) == LN_QUOTE) && (i >= 1) ? \
			ft_lstnew((void *)ft_strndup(s, i + 1), sizeof(char *)) : NULL);
		while (*(*buf + i) != LN_QUOTE)
			i++;
		i++;
		*buf += i;
		ft_lstadd_last(alst, tmp);
	}
	LN_QUOTE = '\0';
}