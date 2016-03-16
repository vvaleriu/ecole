/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_paste.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:56:27 by vincent           #+#    #+#             */
/*   Updated: 2016/03/16 11:35:53 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** on part du debut de la chaine de caractere et on copy dans le buffer pour
** une longueur de 0 -> poistion acutelle + 1. (si on est a la position zero,
** on copie le premier caractere sous le curseur. On va donc copier une
** longeur de 1 [position + 1])
*/
int			copy_from_start(t_var *var)
{
	if (ft_strlen(LN_S))
	{
		ft_strdel(&(LN_CPY));
		LN_CPY = ft_strndup(LN_S, LN_POS + 1);
	}
	return (2);
}

/*
** on part de la position du curseur sur la chane de caracteres et on copie
** dans le buffer jusqu'a la fin de la chaine
** la position acutelle sur cette chaine de catacteres.
*/
int			copy_from_end(t_var *var)
{
	if (ft_strlen(LN_S + LN_POS))
	{
		ft_strdel(&(LN_CPY));
		LN_CPY = ft_strdup(LN_S + LN_POS);
	}
	return (2);
}

/*
** - Si la chaine de caracteres existe
**	- on copie depuis le debut
**	- on deplace le restant vers le debut de la chaine de catacteres
**	- on remet les cases deplacees a 0
**	- on deplace le curseur.
**	- on efface le reste de l'ecran
**	- on affiche la chaine tronquee
**	- on replace le curseur au depart.
*/
int			cut_from_start(t_var *var)
{
	int		i;

	i = ft_strlen(LN_S + LN_POS + 1);
	if (ft_strlen(LN_S))
	{
		copy_from_start(var);
		ft_strncpy(LN_S, LN_S + LN_POS + 1, i);
		while (LN_S[i] != '\0')
		{
			LN_S[i] = '\0';
			i++;
		}
		set_str_cap("rc");
		set_str_cap("cd");
		ft_putstr_cursor(LN_S);
		move_to_origin(var);
	}
	return (2);
}

/*
** - Si la chaine de caracteres existe depuis la position du curseur
**	- on copie depuis la fin
**	- on efface le reste de l'ecran
**	- On met tous les caracteres depuis notre position jusqu'a la fin a zero
*/
int			cut_from_end(t_var *var)
{
	int		i;

	i = LN_POS;
	if (ft_strlen(LN_S + LN_POS))
	{
		copy_from_end(var);
		set_str_cap("cd");
		while (LN_S[i] != '\0')
		{
			LN_S[i] = '\0';
			i++;
		}
	}
	return (2);
}

/*
** ////GERER le stoc\\\\\\\\\\
** - On cree une nouvelle chaine dont la taille est la somme des deux autres
** - On copie dans TMP tous les caracteres de l'ancienne jusqu'au curseur.
** - On copie dans TMP + position du curseur la chaine dans le buffer copy
** - On copie dans TMP + derniere position le reste de la chaine actuelle
*/
int			paste(t_var *var)
{
	char	*tmp;

	if (LN_CPY != NULL)
	{
		//set_str_cap("sc");
		tmp = ft_strnew(ft_strlen(LN_S) + ft_strlen(LN_CPY));
		ft_strncpy(tmp, LN_S, LN_POS);
		ft_strcpy(tmp + LN_POS, LN_CPY);
		ft_strcpy(tmp + LN_POS + ft_strlen(LN_CPY), LN_S + LN_POS);
		ft_putstr_cursor(LN_CPY);
		//set_str_cap("rc");
		ft_strdel(&(LN_S));
		LN_S = tmp;
		update_line_struct(var);
	}
	return (2);
}