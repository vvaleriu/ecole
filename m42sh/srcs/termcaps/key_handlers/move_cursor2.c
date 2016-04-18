/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:03:49 by vincent           #+#    #+#             */
/*   Updated: 2016/04/07 12:07:07 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

/*
** -> Si le caractere suivant est un espace
**		Tant que c'est un espace on avance
**  	Tant que c'est du texte on avance
** -> Sinon si le caractere suivant est du texte
**		On avance jusqu'a la fin du texte
** -> Sinon si le caractere suivant est un operateur
**		On avance jusqu'a la fin de l'operateur
** -> On avance une derniere fois pour etre juste apres le dernier caractere
*/

int		move_to_next_word(t_var *var)
{
	if (LN_POS < (int)ft_strlen(LN_S))
	{
		if (is_space(LN_S[LN_POS + 1]))
		{
			while (LN_POS < (int)LEN(LN_S) && is_space(LN_S[LN_POS + 1]))
				move_to_next_char(var);
			while (LN_POS < (int)LEN(LN_S) && is_text(LN_S[LN_POS + 1]))
				move_to_next_char(var);
		}
		else if (is_text(LN_S[LN_POS + 1]))
			while (LN_POS < (int)LEN(LN_S) && is_text(LN_S[LN_POS + 1]))
				move_to_next_char(var);
		else if (is_operator(LN_S[LN_POS + 1]))
			while (LN_POS < (int)LEN(LN_S) && is_operator(LN_S[LN_POS + 1]))
				move_to_next_char(var);
		move_to_next_char(var);
	}
	return (2);
}

/*
** On deplace le curseur et on met a jour la position
*/

int		move_to_previous_word(t_var *var)
{
	if (LN_POS > 0)
	{
		if (is_space(LN_S[LN_POS - 1]))
		{
			while (LN_POS > 0 && is_space(LN_S[LN_POS - 1]))
				move_to_previous_char(var);
			while (LN_POS > 0 && is_text(LN_S[LN_POS - 1]))
				move_to_previous_char(var);
		}
		else if (is_text(LN_S[LN_POS - 1]))
			while (LN_POS > 0 && is_text(LN_S[LN_POS - 1]))
				move_to_previous_char(var);
		else if (is_operator(LN_S[LN_POS - 1]))
			while (LN_POS > 0 && is_operator(LN_S[LN_POS - 1]))
				move_to_previous_char(var);
	}
	return (2);
}

/*
** - On se trouve sur la deuxieme ligne, sur une colonne avant le prompt
**	On met le y a zero, le x de la taille du prompt, et on place le curseur
** - On se trouve sur la deuxieme ligne, sur une colonne apres le prompt
** Ou bien sur une ligne superieure a 1.
**	On monte d'une ligne, on met a jour la position
*/

int		move_to_up_line(t_var *var)
{
	int		i;

	if (CUR_POS_Y == 1 && CUR_POS_X < PROMPT_LEN)
	{
		CUR_POS_Y--;
		i = PROMPT_LEN - CUR_POS_X;
		set_str_cap("up");
		while (--i >= 0)
			set_str_cap("nd");
		LN_POS = 0;
		CUR_POS_X = PROMPT_LEN;
	}
	else if (CUR_POS_Y > 1 || (CUR_POS_Y == 1 && CUR_POS_X >= PROMPT_LEN))
	{
		set_str_cap("up");
		CUR_POS_Y--;
		LN_POS -= WIN_X;
	}
	return (2);
}

/*
** - Si la longueur de la chaine restante depuis le curseur est superieur
** a la longeur restante de la ligne a afficher (en gros si une ligne suivante
** existe)
**  - s'il existe une ligne complete depuis le curseur, on le descend
**  - sinon on le met a la fin de la ligne du dessous
*/

int		move_to_down_line(t_var *var)
{
	int		i;

	if ((int)ft_strlen(LN_S + LN_POS) > WIN_X - CUR_POS_X)
	{
		if ((int)ft_strlen(LN_S + LN_POS) >= WIN_X)
		{
			set_str_cap("do");
			i = -1;
			while (++i < CUR_POS_X)
				set_str_cap("nd");
			CUR_POS_Y++;
			LN_POS += WIN_X;
		}
		else
		{
			i = (int)ft_strlen(LN_S + LN_POS);
			while (--i >= 0)
				move_to_next_char(var);
		}
	}
	return (2);
}
