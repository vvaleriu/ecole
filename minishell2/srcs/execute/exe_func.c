/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:03:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/03/06 14:14:05 by vvaleriu         ###   ########.fr       */
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
*/

int		exe_semi(t_var *var, t_token *tk)
{
	pid_t	father;
	int		sloc;

	father = fork();
	if (!father)
	{
		execute_tree(var, tk->left);
		exit(0);
	}
	else
	{
		waitpid(father, &sloc, 0);
		execute_tree(var, tk->right);
	}
	return (0);
}

int		exe_pipe(t_var *var, t_token *tk)
{
	pid_t	father;
	int		sloc;
	int		fd[2];

	sloc = 1;
	pipe(fd);
	father = fork();
	if (father)
	{
		wait(0);
		close(fd[1]);
		dup2(fd[0], 0);
		execute_tree(var, tk->right);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		sloc = execute_tree(var, tk->left);
		close(fd[1]);
		exit(sloc);
	}
	return (sloc);
}

int		exe_redir_in(t_var *var, t_token *tk)
{
	pid_t	father;
	int		sloc;
	int		file;

	father = fork();
	if (father)
		waitpid(father, &sloc, 0);
	else
	{
		if (tk->no == OPS_RIN)
			file = open(tk->right->exe[0], O_RDONLY);
		else
			file = open(tk->right->exe[0], O_RDONLY | O_APPEND);
		dup2(file, 0);
		sloc = execute_tree(var, tk->left);
		exit(sloc);
	}
	return (0);
}

int		exe_redir_out(t_var *var, t_token *tk)
{
	pid_t	father;
	int		sloc;
	int		file;

	father = fork();
	if (father)
		waitpid(father, &sloc, 0);
	else
	{
		if (tk->no == OPS_ROUT)
			file = open(tk->right->exe[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			file = open(tk->right->exe[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
		dup2(file, 1);
		sloc = execute_tree(var, tk->left);
		exit(sloc);
	}
	return (0);
}
