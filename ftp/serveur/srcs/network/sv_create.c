#include <ftp_server.h>
#include <netdb.h>
#include <arpa/inet.h>


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

	proto = (struct protoent *)EV(NULL, getprotobyname("tcp"), "getprotobyname error", FORCE_EXIT);
	E(-1, (SV_SOCK = socket(PF_INET, SOCK_STREAM, proto->p_proto)), ERR_SV_SOCK , FORCE_EXIT);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(sv->port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(SV_SOCK, (const struct sockaddr *)&sin, sizeof(sin));
	listen(SV_SOCK, QUEUE_LENGTH);
	sv->max = SV_SOCK;
	sv->fds[0].type = SK_SERV;
	sv->fds[0].ft_read = sv_accept;
	sv->fds[0].ft_write = NULL;
	sv_status(SV_STARTED);
	return (1);
}
