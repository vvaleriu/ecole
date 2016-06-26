/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 17:57:08 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/06/24 22:06:54 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ftp_server.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#ifdef __linux__
# include <sys/time.h>
# include <sys/resource.h>
#endif


/*
** fill_tab fill the array of structure t_pcom with fonctions and how to
** call them.
** ft_get_command : get the name of the command to execute
** ft_get_path : check if the command exist and find its path
** Finally exe_com execute the specified command or prompt the appropriate
** error message
**
** father == 0 means we are into the child
*/

int				exe_command(t_sv_prop *sv, int cl)
{
	char			*binpath;
	pid_t			pid;
	struct rusage	usage;

	printf("[exe_command]\n");
	binpath = NULL;
	pid = fork();
	if (!pid && (binpath = get_path(sv)))
	{
		nt_send_info(CL_SOCK(cl), T_OUTPUT, 1, NULL);
		dup2(CL_SOCK(cl), 1);
		close(CL_SOCK(cl));
		execv(binpath, sv->cmd->cmda);
		ft_strdel(&binpath);
		exit(1);
	}
	else
	{
		//close(CL_SOCK(cl));
		wait4(pid, NULL, 0, &usage);
	}
	return (1);
}
