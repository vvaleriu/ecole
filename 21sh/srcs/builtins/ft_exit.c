/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 18:33:24 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/03/06 12:22:01 by vvaleriu         ###   ########.fr       */
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
	clean_tree(var->root);
	clean_env(var);
	exit(val);
}
