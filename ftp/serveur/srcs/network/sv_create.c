#include <ftp_server.h>
#include <ftp_server_error.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int			sv_create(t_sv_prop *sv)
{
	struct protoent				*proto;
	struct sockaddr_in			sin;

	/*if (!(proto = getprotobyname("tcp")))
	{
		pterr(ERR_UNKNOWN_PROTOCOL);
		return (-1);
	}*/
	proto = (struct protoent *)EV(NULL, getprotobyname("tcp"), "getprotobyname error", 0);
	sv_status(SV_STARTED);
	if (!(sv->fds[0].sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)))
		return (-1);
	sv->fds[0].type = SK_SERV;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(sv->port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(sv->fds[0].sock, (const struct sockaddr *)&sin, sizeof(sin));
	listen(sv->fds[0].sock, QUEUE_LENGTH);
	sv->max = sv->fds[0].sock;
	sv->fds[0].ft_read = sv_accept;
	return (1);
}
