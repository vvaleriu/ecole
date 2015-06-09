#include <ftp_server.h>

/*
** i : case du tableau de sockets clients
*/

void		ft_read(t_sv_prop *sv, int i)
{
	while (get_next_line(CL_SOCK(i), &(sv->cmd->cmd)) > 0)
	{
		sv->cmd->cmda = lexer(sv->cmd->cmd);
		if (check_command(sv))
			exe_command(sv);
		else
			pterr(ERR_CMD_NOT_FOUND);
		ft_strdel(&(sv->cmd->cmd));
		ft_strarray_del(&(sv->cmd->cmda));
	}
	printf("Un socket a lire.\n");
}


/*
{
	while (get_next_line(sv->cl.sock, &(sv->cmd)) > 0)
	{
		sv->cmda = lexer(sv->cmd);
		if (check_command(sv))
			exe_command(sv);
		else
			pterr(ERR_CMD_NOT_FOUND);
		ft_strdel(&(sv->cmd));
		ft_strarray_del(&(sv->cmda));
	}
	printf("Un socket a lire.\n");
}
*/