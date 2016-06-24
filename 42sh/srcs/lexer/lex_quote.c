/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 16:53:08 by vincent           #+#    #+#             */
/*   Updated: 2016/04/07 12:27:40 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>

/*
** imprime la bonne valeur sur le prompteur lorsqu'on doit fermer une quote
*/

static void	print_quote_prompt(t_var *var)
{
	set_str_cap("sc");
	terminal_execute_mode(var->conf);
	if (LN_QUOTE == '\'' && (PROMPT_LEN = ft_strlen("quote>")))
		ft_printf("quote>");
	else if (LN_QUOTE == '\"' && (PROMPT_LEN = ft_strlen("dquote>")))
		ft_printf("dquote>");
	else if (LN_QUOTE == '`' && (PROMPT_LEN = ft_strlen("bquote>")))
		ft_printf("bquote>");
	set_str_cap("sc");
	terminal_input_mode(var->conf);
}

/*
** Verifie s'il s'agit d'une quote normale ou d'une quote echappee et donc que
** l'on ne doit pas prendre en compte
** s : chaine de caractere sur laquelle on checke la validite de la quote
*/

static int	is_valid_quote(t_var *var, char *s, int i)
{
	if (s[i] == LN_QUOTE)
	{
		if (LN_QUOTE == '`')
			return (1);
		if (!i)
			return (1);
		if (s[i - 1] != '\\')
			return (1);
	}
	return (0);
}

/*
** retourne 0 si n'a pas trouve la quote fermante
** retourn 1 si c'est bon
*/

int			check_for_closing_quote(t_var *var, char **tmp, t_list **alst)
{
	int		i;
	char	*del[2];
	t_list	*el;

	i = 0;
	while (LN_S[i] && !is_valid_quote(var, LN_S, i))
		i++;
	if (!LN_S[i])
		return (0);
	PROMPT_LEN = PROMPT_LEN_VALUE;
	i++;
	del[0] = *tmp;
	*tmp = ft_strjoin(*tmp, "\n");
	ft_strdel(&del[0]);
	del[0] = *tmp;
	del[1] = ft_strndup(LN_S, i - 1);
	*tmp = ft_strjoin(*tmp, del[1]);
	ft_strdel(&del[0]);
	ft_strdel(&del[1]);
	el = ft_lstnew((void *)ft_strdup(*tmp), sizeof(char *));
	ft_strdel(tmp);
	LN_S += i;
	ft_lstadd_last(alst, el);
	move_to_next_line(var);
	return (1);
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

void		missing_quote_loop(t_var *var, char *s, t_list **alst)
{
	static char		*tmp = NULL;
	static char		*del = NULL;

	if (tmp == NULL || !check_for_closing_quote(var, &tmp, alst))
	{
		del = tmp;
		tmp = (tmp != NULL ? ft_strjoin(tmp, "\n") : tmp);
		ft_strdel(&del);
		del = tmp;
		tmp = ft_strjoin(tmp, s);
		ft_strdel(&del);
		ft_strdel(&(LN_TMP));
		print_quote_prompt(var);
		read_key(var);
	}
	LN_QUOTE = '\0';
}

/*
** s : ligne du terinal a l'endroit ou on repere la quote
** tmp : element que l'on va ajouter a la liste
** - On avance tant qu'on ne trouve pas la quote fermante
**	- Si on ne l'a pas trouvee, alors on rentre dans missing_quote_loop et on
** 	  sauvegarde le ponteur sur l'espace memoire de la ligne
**	- Sinon on continue le lexing classique
** -----------------------------------------------------------------------------
** quote : type de quote : " ou '
** On repere le type de quote, On avance jusqu'a ce qu'on trouve la meme sinon
** on lance print missing quote
** On garde les guillements dans la chaine trouvee pour eviter des bug d'
** interpretation du parser
*/

void		lex_quote(t_var *var, char **buf, t_list **alst)
{
	char	*s;
	t_list	*tmp;
	int		i;

	i = 1;
	LN_QUOTE = **buf;
	s = *buf;
	while (*(*buf + i) && !is_valid_quote(var, *buf, i))
		i++;
	if (!*(*buf + i))
		missing_quote_loop(var, s, alst);
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
