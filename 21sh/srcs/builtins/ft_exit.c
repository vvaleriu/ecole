/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:33:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 09:51:01 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <ft_minishell2.h>

int		ft_exit(char **exe, void *var1)
{
	t_var	*var;
	int		val;

	var = (t_var *)var1;
	val = (exe && exe[1] ? ft_atoi(exe[1]) : 0);
	if (var->errstr != NULL)
		ft_printf("%s\n", var->errstr);
	restore_terminal(var);
	clean_tree(var->root);
	clean_env(var);
	clean_term_conf(var);
	clean_line(var);
	clean_clist(var);
	clean_history(var);
	clean_var(var);
	exit(val);
}
