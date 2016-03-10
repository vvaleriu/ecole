/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_term_conf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 08:51:31 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/10 08:54:30 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ft_minishell2.h>

void		clean_term_conf(t_var *var)
{
	if (var != NULL && var->conf != NULL)
	{
		free(var->conf);
		var->conf = NULL;
	}
}