/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 08:12:27 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 11:17:47 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

/*
** Afficher les valeurs
*/

void		print_current_list_elem(t_dlist *elem)
{
	ft_putendl((char *)elem->content);
}

/*
** Creer la liste des noms pour l'autocompletion
** Retourne 1 s'il vient de creer la liste
** Retourne 0 si la liste existe deja
** ft_printf("Mot actuel : %s\n", tmp);
** ft_printf("On cherche un %s\n", (look_for_exe(var) ? "exe" : "fichier"));
*/

int			create_list(t_var *var)
{
	char			*tmp;

	if (CLIST == NULL)
	{
		tmp = get_current_word(var);
		if (look_for_exe(var))
			CLIST = create_exe_list(var, tmp);
		else
			CLIST = create_files_list(tmp);
		ft_strdel(&tmp);
		return (1);
	}
	return (0);
}

int			print_com(t_var *var)
{
	t_dlist		*tmp;

	tmp = CLIST;
	set_str_cap("do:cr:sc");
	terminal_execute_mode(var->conf);
	set_str_cap("rc");
	ft_dlstiter(tmp, print_current_list_elem);
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

static int	check_if_tab_completion(t_var *var)
{
	int i;

	i = 0;
	if (!LN_POS)
		return (0);
	while (LN_S[i])
	{
		if (LN_S[i] != '	')
			return (1);
		i++;
	}
	return (0);
}

/*
** On recupere la liste
** On se place au debut du mot et on insere l'element de la liste dans LN_S
** Si la liste existe deja ca veut dire qu'on passe a l'element suivant, sans
** quoi on la cree
*/

int			completion(t_var *var)
{
	int		first;

	if (!check_if_tab_completion(var))
		return (0);
	first = create_list(var);
	if (CLIST)
	{
		if (first)
		{
			while (LN_POS && is_filename(LN_S[LN_POS - 1]))
				move_to_previous_char(var);
			while (is_filename(LN_S[LN_POS]))
				delete_char(var);
		}
		else
		{
			while (LN_POS && is_filename(LN_S[LN_POS - 1]))
				erase_char(var);
		}
		insert_str(var, (char *)CLIST->content);
		CLIST = CLIST->next;
		while (is_filename(LN_S[LN_POS]))
			move_to_next_char(var);
	}
	return (2);
}
