/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:03:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/27 10:40:29 by vvaleriu         ###   ########.fr       */
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
** Permet de gerer la redirection des files descripteurs standards.
** exemple : ls 2>&-
*/
/*O_NONBLOCK | */
int				stdfd_redir(t_token *tk)
{
	int		fd;

	if (tk->exe[1] && tk->exe[1][0] == '&')
	{
		if (tk->exe[1][1] == '-')
			close(ft_atoi(tk->exe[0]));
		else if (ft_isdigit(tk->exe[1][1]))
			dup2(ft_atoi(tk->exe[1] + 1), ft_atoi(tk->exe[0]));
	}
	else if (tk->exe[1] != 0 && (fd = open(tk->exe[1], O_WRONLY | O_CREAT | O_TRUNC, 0644)))
	{
		dup2(fd, ft_atoi(tk->exe[0]));
		return (fd);
	}
	return (-1);
}

/*
**
*/
int				exe_redir_out(t_var *var, t_token *tk)
{
	pid_t	father;
	int		status;
	int		file;

	father = fork();
	if (!father)
	{
		if (tk->no == OPS_ROUT && tk->exe != NULL && tk->exe[0] != NULL)
			file = stdfd_redir(tk);
		else if (tk->no == OPS_ROUT)
			file = open(tk->right->exe[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			file = open(tk->right->exe[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (tk->exe == NULL || tk->exe[0] == NULL)
			dup2(file, 1);
		status = execute_tree(var, tk->left);
		if (file != -1)
			close(file);
		exit(status);
	}
	else
		waitpid(father, &status, 0);
	return (WEXITSTATUS(status));
}
