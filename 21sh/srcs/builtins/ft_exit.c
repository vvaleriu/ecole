/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:33:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/10 12:04:53 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <ft_minishell2.h>

void	ft_exit(char **exe, void *var1)
{
	t_var	*var;
	int		val;

	var = (t_var *)var1;
	val = (exe && exe[1] ? ft_atoi(exe[1]) : 1);
	restore_terminal(var);
	clean_tree(var->root);
	clean_env(var);
	clean_term_conf(var);
	exit(val);
}
