/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:21:03 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/10 15:32:58 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell2.h>

int			return_command(t_var *var)
{
	ft_putstr_fd("Salut les loulous.", var->conf->fd);
	return (2);
}