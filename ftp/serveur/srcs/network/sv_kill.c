#include <ftp_server.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

void		sv_kill(t_sv_prop *sv)
{
	int		i;

	i = 0;
	if (sv->cmd->bin != NULL)
	{
		while (i < BIN_NB)
		{
			free(sv->cmd->bin[i]);
			i++;
		}
		free(sv->cmd->bin);
	}
	close(sv->fds[0].sock);
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
	t_cmd	*tmp;

	tmp = sv->cmd;
	if (tmp->cmd)
		ft_strdel(&tmp->cmd);
}