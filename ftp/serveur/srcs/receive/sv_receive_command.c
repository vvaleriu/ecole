#include <ftp_server.h>
#include <sys/types.h>
#include <sys/socket.h>

/*
** cl : case du tableau de sockets clients (= client)
** remplacer if par un while en cas de commande extrement longue
*/

void		sv_receive_command(t_sv_prop *sv, int cl)
{
	int 	rd;
	int		ret_cmd;

	if ((rd = E(-1, recv(CL_SOCK(cl), sv->fds[cl].rd, BUF_SIZE, 0), ERR_RECV, NO_EXIT)) > 0)
	{
		printf("[sv_receive_command] [client : %d] [commande : %s] [lu : %d]\n", cl, sv->fds[cl].rd, rd);
		sv->cmd->cmda = lexer(sv->fds[cl].rd);
		ret_cmd = execute(sv, cl);
		if (!ret_cmd)
			pterr(ERR_CMD_NOT_FOUND);
		ft_strarray_del(&(sv->cmd->cmda));
		ft_bzero(sv->fds[cl].rd, BUF_SIZE + 1);
	}
	else
		clean_fd(&(sv->fds[cl]));
}