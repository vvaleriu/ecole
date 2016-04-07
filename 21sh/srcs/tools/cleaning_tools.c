/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 08:51:31 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 09:50:48 by vvaleriu         ###   ########.fr       */
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

void		clean_line(t_var *var)
{
	ft_strdel(&(LN_TMP));
	ft_strdel(&(LN_CPY));
}

void		clean_clist(t_var *var)
{
	if (CLIST)
		ft_dlstdel(&(CLIST), delete_completion_list);
}

void 		clean_history(t_var *var)
{
	if (var->hist.start)
		ft_dlstdel(&(var->hist.start), delete_completion_list);
	ft_strdel(&(var->hist.tmp));
}

void		clean_var(t_var *var)
{
	free(var);
	var = NULL;
}