/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_line_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:15:31 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/15 08:44:53 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

/*
** Initialise la structure ligne qui contient la chaine de caracteres tapee
** la longueur max du buffer ainsi que la position actuelle dans la chaine
**
** initialise la position du curseur
** initialise la struture pour son utilisation lors de la capture de la commande
*/
void			init_line_struct(t_var *var)
{
	/*if (var->line.s)
		ft_strdel(&(var->line.s));*/
	var->line.s = ft_strnew(CMD_LENGTH);
	var->line.max = CMD_LENGTH;
	var->line.pos = 0;
	var->hist.cur = NULL;
	CUR_POS_X = PROMPT_LEN;
	CUR_POS_Y = 0;
}

/*
** Met a jour certaines valeur de la structure lors du parcours de l'historique
** Met a jour la longueur acutelle et la longeur max afin de bien gerer les
** mallocs et autres
*/
void			update_line_struct(t_var *var)
{
	var->line.max = ft_strlen(var->line.s);
}