#include <ftp_server.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int			sv_kill(t_sv_prop *sv)
{
	int		i;

	i = 0;
	if (sv->cmd->bin != NULL)
	{
		while (i < BIN_NB)
			free(sv->cmd->bin[i++].name);
		free(sv->cmd->bin);
	}
	kill_sockets(sv);
	kill_cmd(sv);
	close(sv->fds[0].sock);
	return (1);
}

void		kill_sockets(t_sv_prop *sv)
{
	int		i;

	i = 0;
	while (i < MAX_SOCKETS)
		close(CL_SOCK(i++));
	free(sv->fds);
}

void		kill_cmd(t_sv_prop *sv)
{
	ft_strarray_del(&(sv->cmd->path));
	ft_strarray_del(&(sv->cmd->cmda));
	ft_strdel(&sv->cmd->cmd);
}