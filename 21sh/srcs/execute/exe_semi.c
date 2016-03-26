/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_semi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:21:23 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/26 15:14:31 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <libft.h>
#include <ft_minishell2.h>

/*
**	On execute la fonction qui corespond
** !father : child process
** father : wait for the child process to finish first
*/

int		exe_semi(t_var *var, t_token *tk)
{
	pid_t	father;
	int		status;

	status = 1;
	father = fork();
	if (!father)
	{
		execute_tree(var, tk->left);
		//exit(0);
	}
	else
	{
		waitpid(father, &status, 0);
		processus_end_analysis(status);
		ft_printf("Etat de sortie du fils : %d\n");
		execute_tree(var, tk->right);
	}
	return (0);
}

void	processus_end_analysis(int status)
{
	ft_printf("Le fils s'est termine normalement : %s\n", WIFEXITED(status) ? "vrai" : " faux");
	ft_printf("Code de sortie du fils : %d\n", WEXITSTATUS(status));
	ft_printf("Le fils s'est terminé à cause d'un signal.  : %s\n", WIFSIGNALED(status) ? "vrai" : " faux");
	ft_printf("Le fils s'est termine normalement : %s\n", WIFEXITED(status) ? "vrai" : " faux");
}