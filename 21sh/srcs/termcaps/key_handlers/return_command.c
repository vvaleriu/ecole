/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:21:03 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/12 23:31:15 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** une fois la commande validee, on va a la ligne, on affiche ce que l'on veut
*/
/*int			return_command(t_var *var)
{
	move_to_next_line(var);
	ft_putstr_fd(var->line.s, var->conf->fd);
	move_to_next_line(var);
	set_str_cap("sc");
	return (RET);
}*/

int			return_command(t_var *var)
{
	add_to_history(var);
	move_to_next_line(var);
	set_str_cap("sc");
	return (RET);
}