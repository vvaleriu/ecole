/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:38:44 by vincent           #+#    #+#             */
/*   Updated: 2016/04/07 12:21:00 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

/*
** browse key man array to identify the pressed key and execute the predefined
** action.
** Returns 1 if a registered key has been identified.
** Return 0 is the pressed key is not registered.
** Returns -1 if ESC or RET is pressed (program has to stop)
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
		{
			if (i != TAB)
				ft_dlstdel(&(CLIST), delete_completion_list);
			return (KEY_TAB(i).f(var));
		}
		i++;
	}
	ft_dlstdel(&(CLIST), delete_completion_list);
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
	while ((rd = read(var->conf->rfd, var->key_buf, SEL_KEY_SIZE)))
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
