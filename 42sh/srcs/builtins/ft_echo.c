/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:59:04 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 11:13:36 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

int			ft_echo(char **exe, void *var)
{
	int		i;
	int		print_ret;

	i = 0;
	print_ret = (!ft_strcmp(exe[1], "-n") ? 0 : 1);
	var = (void *)var;
	while (++i && exe[i])
	{
		if (i == 1 && print_ret)
			ft_printf("%s%s", exe[i], (exe[i + 1] ? " " : ""));
		else if (i != 1)
			ft_printf("%s%s", exe[i], (exe[i + 1] ? " " : ""));
	}
	if (print_ret)
		ft_putendl("");
	else
		move_to_next_line(var);
	return (0);
}
