/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:03:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/27 10:44:34 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_minishell2.h>

/*
**	On execute la fonction qui corespond
*/
/*static void	display_current_executed_command(t_token *tk)
{
	ft_putstr("______display_current_executed_command, commande executee : \n");
	if (tk->exe)
		ft_putstr_array(tk->exe);
	else
		ft_printf("ops : %d\n", tk->no);
}*/

int		execute_tree(t_var *var, t_token *tk)
{
	if (tk)
		return (var->ef[tk->no](var, tk));
	return (0);
}
