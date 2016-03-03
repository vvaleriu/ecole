/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 19:38:44 by vincent           #+#    #+#             */
/*   Updated: 2016/03/03 13:11:56 by vvaleriu         ###   ########.fr       */
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
		printf("%d\n", ft_strncmp(key_buf, KEY_TAB(i).seq, KEY_TAB(i).seq_len));
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
		if (loop == 2 || loop == 0)
			print_list(conf);
		else if (loop == -1)
			break;
		ft_bzero((void *)key_buf, SEL_KEY_SIZE);
	}
	return (0);
}