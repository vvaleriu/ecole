/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:03:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/24 15:31:41 by vvaleriu         ###   ########.fr       */
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
*/
int		exe_pipe(t_var *var, t_token *tk)
{
	pid_t	father;
	int		sloc;
	int		fd[2];

	sloc = 1;
	pipe(fd);
	father = fork();
	if (!father)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		//close(fd[1]);
		sloc = execute_tree(var, tk->left);
		exit(sloc);
	}
	else
	{
		waitpid(father, &sloc, 0);
		close(fd[1]);
		dup2(fd[0], 0);
		//close(fd[0]);
		execute_tree(var, tk->right);
	}
	return (sloc);
}
/*int		exe_pipe(t_var *var, t_token *tk)
{
	pid_t	father;
	int		sloc;
	int		fd[2];

	sloc = 1;
	pipe(fd);
	father = fork();
	if (!father)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		//close(fd[1]);
		sloc = execute_tree(var, tk->left);
		exit(sloc);
	}
	else
	{
		waitpid(father, &sloc, 0);
		close(fd[1]);
		dup2(fd[0], 0);
		//close(fd[0]);
		execute_tree(var, tk->right);
	}
	return (sloc);
}*/
