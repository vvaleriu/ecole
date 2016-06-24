/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:21:03 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 12:21:11 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>

/*
** On check d'abord si on attend la fermeture d'une quote ou non.
** Si non on renvoit la commande classique sinon on effectue les verifications
** necessaires.
** s : pointeur tmp si on doit reexecuter missing_quote_loop
** ABORD COMMAND : lorsqu'on presse ctrl-c pour une ligne non finie
*/

static int	abord_command(t_var *var)
{
	ft_strdel(&(LN_S));
	LN_HEREDOC = 0;
	LN_QUOTE = '\0';
	ft_strdel(&(LN_TMP));
	ABORD = 0;
	return (RET);
}

int			return_command(t_var *var)
{
	char	*s;

	if (ABORD)
		return (abord_command(var));
	else if (LN_QUOTE == '\0' && !LN_HEREDOC)
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
