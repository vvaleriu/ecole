/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir_out.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:03:16 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/26 08:48:44 by vincent          ###   ########.fr       */
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
static int		stdfd_redir(t_token *tk)
{
	int		fd;

	if (exe[1] && exe[1][0] == '&')
	{
		if (exe[1][1] == '-')
			close(ft_atoi(exe[0]));
		else if (ft_isdigit(exe[1][1]))
			dup2(ft_atoi(exe[1] + 1), ft_atoi(exe[0]));
	}
	else if (exe[1] && exe[1][0] == '\"' && exe[1][ft_strlen(exe[1]) - 1] == '\"')
	{
		if ((fd = open(exe[1])) != -1)
			dup2(fd, ft_atoi(exe[0]));
	}
	return (-1);
}

/*
**
*/
int				exe_redir_out(t_var *var, t_token *tk)
{
	pid_t	father;
	int		sloc;
	int		file;

	file = -1;
	father = fork();
	if (father)
		waitpid(father, &sloc, 0);
	else
	{
		if (tk->no == OPS_ROUT && tk->exe != NULL)
			file = stdfd_redir(tk);
		else
		{
			if (tk->no == OPS_ROUT)
				file = open(tk->right->exe[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			else
				file = open(tk->right->exe[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
			dup2(file, 1);
		}
		sloc = execute_tree(var, tk->left);
		if (file != -1)
			close(file);
		exit(sloc);
	}
	return (0);
}
