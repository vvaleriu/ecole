/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_cursor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 10:40:11 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/22 16:04:40 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** Insere un caractere depuis la position du curseur. Met a jour les positions
** necessaires
*/
void		ft_putchar_cursor(char c)
{
	t_var	*var;

	var = get_instance();
	set_str_cap("im");
	write(1, &c, 1);
	set_str_cap("ei");
	update_trackers(var, 1);
	if (CUR_POS_X == 0)
		set_str_cap("do:cr");
}

/*
** Choisit entre :
** - Si position actuelle est celle de la fin de la ligne, alors on ne fait qu'
**	ajouter le caractere.
** - Sinon, on efface tout ce qui suit le curseur pour reafficher ensuite la
**	version mise a jour de la ligne
** ATTENTION : laisse le curseur en fin de ligne.
*/
void		ft_putchar_cursor_wrap(char c)
{
	t_var	*var;

	var = get_instance();
	if (LN_POS == (int)ft_strlen(var->line.s))
		ft_putchar_cursor(c);
	else
	{
		set_str_cap("cd");
		ft_putstr_cursor(var->line.s + LN_POS);
	}
}