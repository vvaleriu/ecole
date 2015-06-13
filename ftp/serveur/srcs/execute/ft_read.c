#include <ftp_server.h>
#include <sys/types.h>
#include <sys/socket.h>

/*
** i : case du tableau de sockets clients
**
*/

void		ft_read(t_sv_prop *sv, int i)
{
	int 	rd;

	if ((rd = E(-1, recv(CL_SOCK(i), sv->fds[i].rd, BUF_SIZE, 0), ERR_RECV, NO_EXIT)) != -1)
	{
		printf("%s\n", sv->fds[i].rd);
		//printf("%s\n", sv->cmd->cmd);
		sv->cmd->cmda = lexer(sv->fds[i].rd);
		if (check_command(sv))
			exe_command(sv);
		else
			pterr(ERR_CMD_NOT_FOUND);
		ft_strarray_del(&(sv->cmd->cmda));
		ft_bzero(sv->fds[i].rd, rd);
		//ft_strdel(&(sv->cmd->cmd));
	}
}

/*
void		ft_read(t_sv_prop *sv, int i)
{
	while (get_next_line(CL_SOCK(i), &(sv->cmd->cmd)) > 0)
	{
		ft_printf(sv->cmd->cmd);
		sv->cmd->cmda = lexer(sv->cmd->cmd);
		if (check_command(sv))
			exe_command(sv);
		else
			pterr(ERR_CMD_NOT_FOUND);
		ft_strarray_del(&(sv->cmd->cmda));
	}
	ft_strdel(&(sv->cmd->cmd));
}
*/