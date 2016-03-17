/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_cursor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:26:54 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/17 14:51:42 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ft_minishell2.h>

/*
** Inserre une chaine de caracteres depuis la position du curseur. Met a jour
** les positions necessaires
*/
void		ft_putstr_cursor(char *str)
{
	t_var	*var;
	t_tconf	*conf;

	var = get_instance();
	conf = var->conf;
	set_str_cap("im");
	while (*str != '\0')
	{
		write(conf->fd, &(*str), 1);
		str++;
		update_trackers(var, 1);
	}
	//print_term_status(var);
	set_str_cap("ei");
}

/*
** Choisit entre :
** - Si position actuelle est celle de la fin de la ligne, alors on ne fait qu'
**	ajouter les caracteres.
** - Sinon, on efface tout ce qui suit le curseur pour reafficher ensuite la
**	version mise a jour de la ligne
** ||||||   ATTENTION : laisse le curseur en fin de ligne. ||||||||
*/
void	ft_putstr_cursor_wrap(t_var *var)
{
	if (LN_POS == (int)ft_strlen(var->line.s))
		ft_putstr_cursor((var->line.s) + LN_POS);
	else
	{
		set_str_cap("cd");
		ft_putstr_cursor(var->line.s + LN_POS);
	}
}
