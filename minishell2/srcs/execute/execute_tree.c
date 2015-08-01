/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:03:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/02/17 12:57:02 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_minishell2.h>

/*
**	On execute la fonction qui corespond
*/

int		execute_tree(t_var *var, t_token *tk)
{
	if (tk)
		var->ef[tk->no](var, tk);
	return (1);
}
