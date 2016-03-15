/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:03:49 by vincent           #+#    #+#             */
/*   Updated: 2016/03/15 09:18:54 by vvaleriu         ###   ########.fr       */
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

int		move_to_up_line(t_var *var)
{
	t_tconf		*conf;

	
	conf = var->conf;
	(void)conf;
	set_str_cap("do");
	return (2);
}

int		move_to_down_line(t_var *var)
{
	t_tconf		*conf;
	
	conf = var->conf;
	(void)conf;
	set_str_cap("do");
	return (2);
}
