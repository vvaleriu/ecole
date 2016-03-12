/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:38:44 by vincent           #+#    #+#             */
/*   Updated: 2016/03/12 23:49:12 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

static void			init_line_struct(t_var *var)
{
	/*if (var->line.s)
		ft_strdel(&(var->line.s));*/
	var->line.s = ft_strnew(CMD_LENGTH);
	var->line.max = CMD_LENGTH;
	var->line.pos = 0;
	var->hist.cur = NULL;
}

/*
** browse key man array to identify the pressed key and execute the predefined
** action.
** Returns 1 if a registered key has been identified.
** Return 0 is the pressed key is not registered.
** Returns -1 if ESC or RET is pressed (program has to stop)
**
*/

static int			key_identifier(t_var *var)
{
	int			i;
	t_tconf		*conf;

	i = 0;
	conf = var->conf;
	while (i < KEY_NUMBER)
	{
		if (!ft_strncmp(var->key_buf, KEY_TAB(i).seq, KEY_TAB(i).seq_len))
			return (KEY_TAB(i).f(var));
		i++;
	}
	return (0);
}

/*
** On nettoie le buffer, et on stocke la position du curseur.
** On stocke la touche pressee dans key_buf. Une fois identifiee, on vide le
** buffer de lecture
** loop : retour de l'identificateur de touche pressee
** rd : nombre de caracteres lus
** 4 = retour
*/
int					read_key(t_var *var)
{
	int		loop;
	int		rd;

	ft_bzero((void *)(var->key_buf), SEL_KEY_SIZE);
	init_line_struct(var);
	while ((rd = read(0, var->key_buf, SEL_KEY_SIZE)))
	{
		loop = key_identifier(var);
		if (!loop)
			insert_char(var);
		ft_bzero((void *)(var->key_buf), SEL_KEY_SIZE);
		if (loop == RET)
			return (RET);
	}
	return (0);
}