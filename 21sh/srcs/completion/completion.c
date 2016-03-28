/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 08:12:27 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/28 12:50:10 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>
/*
** Afficher les valeurs
*/

static void		print_current_list_elem(t_dlist *elem)
{
	ft_putendl((char *)elem->content);
}

int 		completion(t_var *var)
{
	char		*tmp;
	t_dlist		*list;

	set_str_cap("do:cr:sc");
	terminal_execute_mode(var->conf);
	set_str_cap("rc");
	ft_printf("On cherche un %s\n", (look_for_exe(var) ? "exe" : "fichier"));
	ft_printf("Mot actuel : %s\n", (tmp = get_current_word(var)));
	if (look_for_exe(var))
	{
		list = create_exe_list(var, tmp);
		ft_printf("Build_exe_list - Longeur de la liste : %d", ft_dlstlen(list));
		ft_dlstiter(list, print_current_list_elem);
		ft_dlstdel(&list, delete_completion_list);
	}
	else
	{
		list = create_files_list(tmp);
		ft_printf("Build_files_list - Longeur de la liste : %d", ft_dlstlen(list));
		ft_dlstiter(list, print_current_list_elem);
		ft_dlstdel(&list, delete_completion_list);
	}
	ft_strdel(&tmp);
	set_str_cap("sc");
	terminal_input_mode(var->conf);
	set_str_cap("rc");
	set_str_cap("sc");
	CUR_POS_X = PROMPT_LEN;
	CUR_POS_Y = 0;
	if (ft_strlen(LN_S))
	{
		ft_putstr_cursor(LN_S);
		update_line_struct(var);
		LN_POS = ft_strlen(LN_S);
	}
	return (2);
}



/*
** Regarde la position du curseur pour savoir sur quel mot on se trouve. Si on
** est sur le premier mot ou un mot qui suit directement une operande, alors on
** va chercher un executable, sans quoi on cherche un fichier ou dossier dans le
** dossier courant
** En cherche a partir de la position  -1
** Si on est sur la premiere position on ne cherche rien.
** Retourne 1 si vrai, sinon 0
**
** Si on est sur un espace ou sur la fin on recule jusqu'au mot precedant.
** une fois sur le mot on se place avant ce mot pour savoir si c'est le premier
** ou non.
** Si c'est le premier (on est au debut de la ligne) on renvoie alors VRAI.
** Sinon on regarde si le mot precedant est une operance || ou && ou bien ";"
** dans ce cas on revoie vrai aussi.
** sinon on renvoie faux
*/
int			look_for_exe(t_var *var)
{
	int		i;

	i = LN_POS;
	if (LN_POS != 0 && currently_on_a_word(var))
	{
		i = (LN_S[i] == '\0' || ft_isspace(LN_S[i]) ? i - 1 : i);
		while (i && ft_isalnum(LN_S[i]))
			i--;
		while (ft_isspace(LN_S[i]) || LN_S[i] == '\0')
		i--;
	}
	if (!i || LN_S[i] == '&' || LN_S[i] == '|' || LN_S[i] == ';')
		return (1);
	return (0);
}

/*
** Dit si on doit faire une recherche sur rien ou bien sur un mot
*/
int			currently_on_a_word(t_var *var)
{
	if (LN_S[LN_POS] == '\0' && LN_POS == 0)
		return (0);
	if (ft_isalnum(LN_S[LN_POS]) || (LN_POS && ft_isalnum(LN_S[LN_POS - 1])))
		return (1);
	return (0);
}

char		*get_current_word(t_var *var)
{
	char	*ret;
	int		i;
	int		j;

	ret = NULL;
	i = LN_POS;
	if (currently_on_a_word(var))
	{
		i = (LN_S[i] == '\0' || ft_isspace(LN_S[i]) ? i - 1 : i);
		j = i + 1;
		while (i && ft_isalnum(LN_S[i]))
			i--;
		ft_printf("i : %d\n", i);
		ret = ft_strndup(LN_S + i, j - i);
	}
	return (ret);
}










