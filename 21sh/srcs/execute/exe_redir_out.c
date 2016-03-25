/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:03:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/25 18:24:08 by vincent          ###   ########.fr       */
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
