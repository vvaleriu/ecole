#include <ftp_server.h>

/*
** i : case du tableau de sockets clients
**
*/

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