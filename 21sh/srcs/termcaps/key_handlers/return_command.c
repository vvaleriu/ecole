/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:21:03 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/11 09:17:00 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

int			return_command(t_var *var)
{
	ft_putstr_fd(var->line.s, var->conf->fd);
	return (2);
}