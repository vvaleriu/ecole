#include <ftp_server.h>

void		execute_sv(t_sv_prop *sv)
{
	get_next_line(0, &sv->cmd->gnl);
	if (!ft_strcmp("status", sv->cmd->gnl))
		sv_socket_state(sv,"LOL");
	else
		printf("%s\n", ERR_SV_CMD_NOT_FOUND);
}