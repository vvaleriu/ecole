/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:03:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/27 11:10:57 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <libft.h>
#include <42sh.h>

int		exe_redir_in(t_var *var, t_token *tk)
{
	pid_t	father;
	int		status;
	int		file;

	father = fork();
	if (!father)
	{
		if (tk->no == OPS_RIN)
			file = open(tk->right->exe[0], O_RDONLY);
		else
			file = open(tk->right->exe[0], O_RDONLY | O_APPEND);
		if (file != -1)
			dup2(file, 0);
		exit(execute_tree(var, tk->left));
	}
	else
		waitpid(father, &status, 0);
	return (WEXITSTATUS(status));
}
