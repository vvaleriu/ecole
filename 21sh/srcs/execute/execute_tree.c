/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:03:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/10 18:11:33 by vincent          ###   ########.fr       */
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
	{
		//display_current_executed_command(tk);
		var->ef[tk->no](var, tk);
	}
	return (1);
}
