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

int			cl_connect(t_cl_prop *cl)
{
	struct protoent				*proto;
	struct sockaddr_in			sin;
	int							yes;

	proto = NULL;
	yes = 1;
	EV(NULL, (proto = getprotobyname("tcp")), ERR_UNKNOWN_PROTOCOL, FORCE_EXIT);
	if (!(cl->fd.sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)))
		return (-1);
	if (setsockopt(SOCK, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
	{
    	perror("setsockopt");
    	exit(1);
	}  
	cl->fd.ft_read = cl_receive_prepare;
	cl->fd.ft_write = cl_send_prepare;
	cl->max = cl->fd.sock + 1;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(cl->port);
	printf("address: %s:%d\n", cl->ip, cl->port);
	sin.sin_addr.s_addr = inet_addr(cl->ip);
	E(-1, connect(cl->fd.sock, (const struct sockaddr *)&sin, sizeof(sin)), ERR_CONNECT, FORCE_EXIT);
	printf("connecte.\n");
	return (1);
}