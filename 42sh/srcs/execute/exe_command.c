/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 17:57:08 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/04/07 11:37:07 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <42sh.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
** Si on a un argument
*/

static void		check_for_back_quote(t_var *var, char **com)
{
	int		i;

	i = 0;
	while (com[i])
	{
		if (com[i][0] == '`')
			execute_back_quote(var, &(com[i]));
		i++;
	}
}

static void		fill_argument(int fd, char **arg)
{
	int		rd;
	char	*ret;
	char	*del;
	char	buf[500];

	ft_strdel(arg);
	ret = NULL;
	while ((rd = read(fd, buf, 499)))
	{
		buf[rd] = '\0';
		buf[rd - 1] = (buf[rd - 1] == '\n' ? '\0' : buf[rd - 1]);
		del = ret;
		ret = ft_strjoin(ret, buf);
		ft_strdel(&del);
	}
	*arg = ret;
}

void			execute_back_quote(t_var *var, char **arg)
{
	pid_t	father;
	int		status;
	int		fd[2];
	int		saved_fds[2];

	save_std_fds(saved_fds);
	pipe(fd);
	father = fork();
	if (!father)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		var->line.s = ft_strndup((*arg) + 1, ft_strlen(*arg) - 2);
		var->list = NULL;
		proceed_to_execution(var);
		exit(0);
	}
	else
	{
		waitpid(father, &status, 0);
		close(fd[1]);
		fill_argument(fd[0], arg);
		close(fd[0]);
		restore_std_fds(saved_fds);
	}
}

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
**			  s'agit donc d'une commande systeme classique
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
	if (com && status == -1 && (path = get_path(com[0], var->tenv)))
	{
		ft_strrev(com[0]);
		check_for_back_quote(var, com);
		father = fork();
		if (!father)
		{
			sig_catcher_fork();
			exit(execve(path, com, var->tenv));
		}
		if (father > 0)
		{
			waitpid(father, &status, 0);
			status = WEXITSTATUS(status);
		}
		ft_strdel(&path);
	}
	return (status);
}
