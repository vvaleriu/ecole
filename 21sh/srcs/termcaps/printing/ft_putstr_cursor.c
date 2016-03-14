/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_cursor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:26:54 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/14 14:43:11 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ft_minishell2.h>

void		ft_putstr_cursor(char *str)
{
	t_var	*var;
	t_tconf	*conf;

	var = get_instance();
	conf = var->conf;
	set_str_cap("im");
	while (*str != '\0')
	{
		write(conf->fd, &(*str), 1);
		str++;
		var->line.pos++;
	}
	set_str_cap("ei");
}

/*
** On part de la position actuelle. On efface tout, on imprime tout le reste
** et on revient a la position
*/
void	ft_putstr_cursor_wrap(t_var *var)
{
	int		original_position;

	original_position = var->line.pos;
	set_str_cap("cd");
	ft_putstr_cursor((var->line.s) + original_position);
	original_position = var->line.pos;
	while (original_position)
	{
		set_str_cap("le");
		original_position--;
	}
}