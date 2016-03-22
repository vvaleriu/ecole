/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:21:25 by vincent           #+#    #+#             */
/*   Updated: 2016/03/22 14:14:53 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

int			cl_screen(t_var *var)
{
	set_str_cap("cl");
	set_str_cap("sc");
	CUR_POS_X = PROMPT_LEN;
	CUR_POS_Y = 0;
	terminal_execute_mode(var->conf);
	set_str_cap("rc");
	/*if ((var->conf->fd = init_fd(var->conf->fd)) == -1)
			return (-1);*/
	ft_putstr_fd("$>", var->conf->fd);
	set_str_cap("sc");
	terminal_input_mode(var->conf);
	set_str_cap("rc");
	if (ft_strlen(LN_S))
	{
		ft_putstr_cursor(LN_S);
		update_line_struct(var);
		LN_POS = ft_strlen(LN_S);
	}
	return (2);
}