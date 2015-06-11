#include <ftp_server.h>
#include <ftp_server_error.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

/*
**	sv->fds[0].ft_read = sv_accept;
**	sv->fds[0].ft_read : correspond a la function appelee lorsque le socket server 
**	recoit des donnees. On lui met la fonction accept car c'est elle qui va lire les donnees
**	recues dans le socket (adresse, et longueur d'adresse) pour creer un socket client que l'on
**	va par la suite ajouter au tableau de sockets client sv->fds[1 et +]
*/

int			sv_create(t_sv_prop *sv)
{
	struct protoent				*proto;
	struct sockaddr_in			sin;

	proto = (struct protoent *)EV(NULL, getprotobyname("tcp"), "getprotobyname error", NO_EXIT);
	if (!(SV_SOCK = socket(PF_INET, SOCK_STREAM, proto->p_proto)))
		return (-1);
	sv->fds[0].type = SK_SERV;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(sv->port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(SV_SOCK, (const struct sockaddr *)&sin, sizeof(sin));
	listen(SV_SOCK, QUEUE_LENGTH);
	sv->max = SV_SOCK;
	sv->fds[0].ft_read = sv_accept;
	printf("Server socket: %d\n", SV_SOCK);
	sv_status(SV_STARTED);
	return (1);
}
