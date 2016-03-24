/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_semi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:21:23 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/24 15:22:02 by vvaleriu         ###   ########.fr       */
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