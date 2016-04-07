/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:53:59 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 07:53:46 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** Regarde la position du curseur pour savoir sur quel mot on se trouve. Si on
** est sur le premier mot ou un mot qui suit directement une operande, alors on
** va chercher un executable, sans quoi on cherche un fichier ou dossier dans le
** dossier courant
** En cherche a partir de la position  -1
** Si on est sur la premiere position on ne cherche rien.
** Retourne 1 si vrai, sinon 0
** -----------------------------------------------------------------------------
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
		while (i && is_filename(LN_S[i]))
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
	if (is_filename(LN_S[LN_POS]) || (LN_POS && is_filename(LN_S[LN_POS - 1])))
		return (1);
	return (0);
}

/*
** Permet de recuperer le mot ou l'expression que l'on doit chercher pour
** la completion
** Si on n'est pas sur un mot on retourne null
** Si on est deja sur un mot
**	- Si on est a la fin de la ligne ou bien sur un espace, on recule d'une case
**	- On sauvegarde la place
*/
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
		while (LN_S[j] != '\0' && !ft_isspace(LN_S[j]))
			j++;
		while (i && is_filename(LN_S[i - 1]))
			i--;
		ret = ft_strndup(LN_S + i, j - i);
	}
	return (ret);
}
