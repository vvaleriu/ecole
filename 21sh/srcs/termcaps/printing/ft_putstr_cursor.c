/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_cursor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:26:54 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/14 23:05:16 by vincent          ###   ########.fr       */
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
		if (!((CUR_POS_X + 1) % var->conf->w.ws_col))
		{
			CUR_POS_X = 0;
			CUR_POS_Y++;
		}
		else
			CUR_POS_X++;
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
	if (var->line.pos == (int)ft_strlen(var->line.s) - 1)
		ft_putstr_cursor((var->line.s) + original_position);
	else
	{	
		set_str_cap("cd");
		ft_putstr_cursor((var->line.s) + original_position);
		original_position = ft_strlen(var->line.s) - original_position;
		while (original_position - 1)
		{
			//set_str_cap("le");
			move_to_previous_char(var);
			original_position--;
		}
	}

}