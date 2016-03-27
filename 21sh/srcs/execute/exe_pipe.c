/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:03:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/27 10:37:50 by vvaleriu         ###   ########.fr       */
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
** father represente le PID du fils dans le pere
** !father : processus fils. Correspond a la branche gauche de l'arbre
** autre : on est dans le processus pere execute en second. Correspond a la
** branche droite de l'arbre
**
** Si lexecution de la premiere commande est ok alors le status devient celui
** de l'execution de la commande de droite, sinon il reste le status d'erreur
*/
int		exe_pipe(t_var *var, t_token *tk)
{
	pid_t	father;
	int		status;
	int		fd[2];

	pipe(fd);
	father = fork();
	if (!father)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		exit(execute_tree(var, tk->left));
	}
	else
	{
		waitpid(father, &status, 0);
		close(fd[1]);
		dup2(fd[0], 0);
		if (!WEXITSTATUS(status))
			status = execute_tree(var, tk->right);
		else
			execute_tree(var, tk->right);
	}
	return (status);
}
