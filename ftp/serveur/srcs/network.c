#include <ftp_server.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/wait.h>

/*
** Create the server and accept client connection
*/

int			lauch_server(t_sv_prop *sv)
{
	pid_t	father;

	father = fork();
	if (father == 0)
	{
		if (create_server(sv) == -1)
			return (-1);
		if ((sv->cl.sock = accept(sv->sock, (struct sockaddr *)&(sv->cl.sin), &(sv->cl.slen))) == -1)
			return (-1);
	}
	else
		wait(0);
	return (1);
}

int			create_server(t_sv_prop *sv)
{
	struct protoent				*proto;
	struct sockaddr_in			sin;

	if (!(proto = getprotobyname("tcp")))
	{
		pterr(ERR_UNKNOWN_PROTOCOL);
		return (-1);
	}
	printf("Server running.\n");
	if (!(sv->sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)))
		return (-1);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(sv->port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(sv->sock, (const struct sockaddr *)&sin, sizeof(sin));
	listen(sv->sock, QUEUE_LENGTH);
	return (1);
}

void		kill_server(t_sv_prop *sv)
{
	int		i;

	i = 0;
	if (sv->cmd != null)
	{
		while (i < CMD_NB)
		{
			free(sv->cmd[i])
			i++;
		}
		free(sv->cmd);
	}
	close(sv->cl.sock);
	close(sv->sock);
}