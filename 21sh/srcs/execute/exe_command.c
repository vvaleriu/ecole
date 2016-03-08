/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 17:57:08 by vvaleriu          #+#    #+#             */
/*   Updated: 2015/03/06 14:13:40 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <ft_minishell2.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
** fill_tab fill the array of structure t_pcom with fonctions and how to
** call them.
** ft_get_command : get the name of the command to execute
** ft_get_path : check if the command exist and find its path
** Finally exe_com execute the specified command or prompt the appropriate
** error message
*/

static int		exec_bin(char **com, t_var *var)
{
	int		i;

	i = 0;
	while (i < BIN_NB)
	{
		if (!ft_strcmp(com[0], var->bin[i].na))
		{
			var->bin[i].f(com, (void *)var);
			return (1);
		}
		i++;
	}
	return (0);
}

int				exe_command(t_var *var, t_token *tk)
{
	pid_t		father;
	char		*path;
	char		**com;

	com = (tk->exe ? tk->exe : NULL);
	if (com != NULL && !exec_bin(com, var))
	{
		if (com && (path = get_path(com[0], var->tenv)))
		{
			father = fork();
			if (father > 0)
				wait(0);
			if (father == 0)
			{
				execve(path, com, var->tenv);
				exit(1);
			}
			ft_strdel(&path);
		}
	}
	return (1);
}
