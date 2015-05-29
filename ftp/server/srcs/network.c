#include <ftp_server.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int			create_server(t_sv_prop *prop)
{
	struct protoent				*proto;
	struct sockaddr_in			sin;

	if (!(proto = getprotobyname("tcp")))
	{
		pterr(ERR_UNKNOWN_PROTOCOL);
		return (-1);
	}
	if (!(prop->sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)))
		return (-1);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(prop->port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(prop->sock, (const struct sockaddr *)&sin, sizeof(sin));
	listen(prop->sock, QUEUE_LENGTH);
	return (1);
}