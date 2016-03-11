/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:38:44 by vincent           #+#    #+#             */
/*   Updated: 2016/03/11 09:46:44 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

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
** On stocke la touche pressee dans key_buf. Une fois identifiee, on vide le
** buffer de lecture
** loop : retour de l'identificateur de touche pressee
** rd : nombre de caracteres lus
*/
int			read_key(t_var *var)
{
	int		loop;
	int		rd;

	ft_bzero((void *)(var->key_buf), SEL_KEY_SIZE);
	while ((rd = read(0, var->key_buf, SEL_KEY_SIZE)))
	{
		loop = key_identifier(var);
		if (!loop)
			insert_char(var);
		ft_bzero((void *)(var->key_buf), SEL_KEY_SIZE);
	}
	return (0);
}