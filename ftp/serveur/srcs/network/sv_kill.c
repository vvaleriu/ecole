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
		free(sv->bin);
	}
	close(sv->fds[0].sock);
}