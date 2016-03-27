/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 17:57:08 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/03/27 11:00:12 by vvaleriu         ###   ########.fr       */
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
			return (var->bin[i].f(com, (void *)var));
		i++;
	}
	return (-1);
}

/*
** bin_exit : si le retour est -1 c'est que l'on n'a pas trouve le builtin. Il
			  s'agit donc d'une commande systeme classique
** 			  si le builtin a ete execute alors la variable contient le retour
**			  de la fonction executee.
*/
int				exe_command(t_var *var, t_token *tk)
{
	pid_t		father;
	char		*path;
	char		**com;
	int			status;

	com = (tk->exe ? tk->exe : NULL);
	status = exec_bin(com, var);
	if (com != NULL && status == -1)
	{
		if (com && (path = get_path(com[0], var->tenv)))
		{
			ft_strrev(com[0]);
			father = fork();
			if (!father)
				exit(execve(path, com, var->tenv));
			if (father > 0)
			{
				waitpid(father, &status, 0);
				status = WEXITSTATUS(status);
			}
			ft_strdel(&path);
		}
	}
	return (status);
}
