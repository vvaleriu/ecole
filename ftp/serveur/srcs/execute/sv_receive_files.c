#include <ftp_server.h>
#include <sys/types.h>
#include <sys/socket.h>

/*
** i : case du tableau de sockets clients (= client)
**
*/

void		sv_receive_command(t_sv_prop *sv, int cl)
{
	int 	rd;
	int		ret_cmd;

	if ((rd = E(-1, recv(CL_SOCK(cl), sv->fds[cl].rd, BUF_SIZE, 0), ERR_RECV, NO_EXIT)) > 0)
	{
		printf("ft_read [client : %d] [commande : %s] [lu : %d]\n", cl, sv->fds[cl].rd, rd);
		sv->cmd->cmda = lexer(sv->fds[cl].rd);
		ret_cmd = execute(sv, cl);
		if (!ret_cmd)
			pterr(ERR_CMD_NOT_FOUND);
		ft_strarray_del(&(sv->cmd->cmda));
		ft_bzero(sv->fds[cl].rd, rd);
	}
	else
		clean_fd(&(sv->fds[cl]));
}
sv->cmd->cmda = lexer(sv->fds[cl].rd);