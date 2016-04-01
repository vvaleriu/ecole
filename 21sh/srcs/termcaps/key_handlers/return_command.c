/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:21:03 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/02 00:29:27 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** une fois la commande validee, on va a la ligne, on affiche ce que l'on veut
*/
/*int			return_command(t_var *var)
{
	move_to_next_line(var);
	ft_putstr_fd(var->line.s, var->conf->wfd);
	move_to_next_line(var);
	set_str_cap("sc");
	return (RET);
}*/

/*
** On check d'abord si on attend la fermeture d'une quote ou non.
** Si non on renvoit la commande classique sinon on effectue les verifications
** necessaires.
** s : pointeur tmp si on doit reexecuter missing_quote_loop
*/
int			return_command(t_var *var)
{
	char	*s;


	if (LN_QUOTE == '\0' && !LN_HEREDOC)
	{
		LN_TMP = LN_S;
		add_to_history(var);
		move_to_end(var);
		move_to_next_line(var);
		set_str_cap("sc");
		return (RET);
	}
	else if (LN_HEREDOC)
	{
		dredir_loop(var);
		return (RET);
	}
	else
	{
		LN_TMP = LN_S;
		missing_quote_loop(var, (s = LN_S), &(var->list));
		return (RET);
	}
}