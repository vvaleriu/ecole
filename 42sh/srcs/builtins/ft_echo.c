/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 11:59:04 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/06/23 19:07:22 by gschroed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>

int			ft_echo(char **exe, void *var)
{
	int		i;
	int		print_ret;

	i = 0;
	print_ret = 1;
	var = (void *)var;
	while (++i && exe[i])
	{
		if (i == 1 && print_ret)
			ft_printf("%s%s", exe[i], (exe[i + 1] ? " " : ""));
		else if (i != 1)
			ft_printf("%s%s", exe[i], (exe[i + 1] ? " " : ""));
	}
	move_to_next_line(var);
	return (0);
}
