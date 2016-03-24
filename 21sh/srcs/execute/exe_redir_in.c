/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:03:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/24 15:25:54 by vvaleriu         ###   ########.fr       */
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
