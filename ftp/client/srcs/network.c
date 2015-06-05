#include <ftp_client.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

/*
** On creer un socket (fn socket()), ensuite on recupere l'adresse du server et les proprietes
** pour remplir la structure sockaddr avec les proprietes du server.
** Enfin on connect le s
*/

int			connect_client(t_cl_prop *prop)
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
	printf("address: %s:%d\n", prop->ip, prop->port);
	sin.sin_addr.s_addr = inet_addr(prop->ip);
	if (connect(prop->sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		printf("connect error.\n");
		exit(2);
	}
	else
	{
		printf("connecte.\n");
	}
	return (1);
}