#include <ftp_server.h>
#include <sys/types.h>
#include <sys/socket.h>

/*
** i : case du tableau de sockets clients (= client)
**
*/

void		ft_read(t_sv_prop *sv, int i)
{
	int 	rd;
	int		ret_cmd;

	if ((rd = E(-1, recv(CL_SOCK(i), sv->fds[i].rd, BUF_SIZE, 0), ERR_RECV, NO_EXIT)) != -1)
	{
		printf("%s\n", sv->fds[i].rd);
		sv->cmd->cmda = lexer(sv->fds[i].rd);
		if ((ret_cmd = check_command(sv)) > 0)
			exe_command(sv, i);
		else if (!ret_cmd)
			pterr(ERR_CMD_NOT_FOUND);
		ft_strarray_del(&(sv->cmd->cmda));
		ft_bzero(sv->fds[i].rd, rd);
	}
}