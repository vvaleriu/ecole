/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:38:44 by vincent           #+#    #+#             */
/*   Updated: 2015/08/05 02:07:05 by vincent          ###   ########.fr       */
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
		//printf("%d\n", ft_strncmp(key_buf, KEY_TAB(i).seq, KEY_TAB(i).seq_len));
		if (!ft_strncmp(key_buf, KEY_TAB(i).seq, KEY_TAB(i).seq_len))
			return (KEY_TAB(i).f(conf, key_buf));
		i++;
	}
	return (0);
}

int			get_key(t_tconf *conf)
{
	char	key_buf[SEL_KEY_SIZE];
	int		loop;
	int		rd;

	while ((rd = read(0, key_buf, SEL_KEY_SIZE)))
	{
		loop = key_identifier(conf, key_buf);
		if (loop == 2)
			print_list(conf);
		if (loop == -1)
			break;
	}
	return (0);
}