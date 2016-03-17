/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:03:49 by vincent           #+#    #+#             */
/*   Updated: 2016/03/17 15:22:56 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

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
** Si on se trouve sur la seconde ligne
** - Si on se trouve apres le prompteur
*/
int		move_to_up_line(t_var *var)
{
	int		i;

	if (CUR_POS_Y == 1 && CUR_POS_X >= PROMPT_LEN)
	{
		set_str_cap("up");
		CUR_POS_Y--;
		LN_POS -= WIN_X;
	}
	else if (CUR_POS_Y == 1 && CUR_POS_X < PROMPT_LEN)
	{
		CUR_POS_Y--;
		i = PROMPT_LEN - CUR_POS_X;
		LN_POS -= WIN_X + i;
		while (--i >= 0)
			set_str_cap("nd");
		LN_POS = 0;
	}
	else if (CUR_POS_Y > 1)
	{
		set_str_cap("up");
		CUR_POS_Y--;
		LN_POS -= WIN_X;
	}
	return (2);
}

int		move_to_down_line(t_var *var)
{
	int		i;

	if (LN_POS + WIN_X <= (int)ft_strlen(LN_S))
	{
		set_str_cap("do");
		CUR_POS_Y++;
		LN_POS += WIN_X;
	}
	else if ((int)ft_strlen(LN_S + LN_POS) >= WIN_X - CUR_POS_X)
	{
		i = (int)ft_strlen(LN_S) - LN_POS;
		while (--i >= 0)
			move_to_next_char(var);
	}
	return (2);
}
