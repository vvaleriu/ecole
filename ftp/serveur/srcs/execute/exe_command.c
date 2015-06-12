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
#include <ftp_server.h>
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

int				exe_command(t_sv_prop *sv)
{
	pid_t		father;
	char		*binpath;

	binpath = NULL;
	father = fork();
	if (father == 0 && (binpath = get_path(sv)))
	{
		execve(binpath, sv->cmd->cmda, sv->cmd->env);
		ft_strdel(&binpath);
		exit(1);
	}
	else
		wait(0);
	return (1);
}
