/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:38:44 by vincent           #+#    #+#             */
/*   Updated: 2015/08/03 18:10:00 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

/*
** browse key man array to identify the pressed key and execute the predefined
** action.
** Returns 1 if a registered key has been identified.
** Return 0 is the pressed key is not registered.
** Returns -1 if ESC or RET is pressed (program has to stop)
**
*/

static int			key_identifier(t_tconf *conf, char *key_buf)
{
	int		i;

	i = 0;
	while (i < KEY_NUMBER)
	{
		if (!ft_strncmp(key_buf, KEY_TAB(i).seq, KEY_TAB(i).seq_len))
			return (KEY_TAB(i).f(conf, key_buf));
		i++;
	}
	return (0);
}

int			get_key(t_tconf *conf)
{
	int		key_ident_ret;
	char	key_buf[KEY_SIZE];

	key_ident_ret = 1;
	while (read(0, key_buf, KEY_SIZE))
	{
		key_ident_ret = key_identifier(conf, key_buf);
		if (key_ident_ret == 2)
			print_list(conf);
		else if (key_ident_ret == -1)
			break;
	}
	return (0);
}