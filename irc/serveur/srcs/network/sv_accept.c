#include <irc_server.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

/*
** Parcours le tableau de structure socket. Lorsqu'il trouve une case vide il associe 
** le socket retourne par la fonction accept a la case socket de la structure.
** i = 1 car le 0 est le socket du serveur.
*/

void			sv_accept(t_sv_prop *sv)
{
	int					i;
	struct sockaddr_in	csin;
	socklen_t			csin_len;
	
	i = 1;
	while (i < MAX_SOCKETS && sv->fds[i].type != SK_FREE)
		i++;
	if (i == MAX_SOCKETS)
		pterr(ERR_MAX_CONNECTIONS);
	else if ((sv->fds[i].sock = accept(SV_SOCK, (struct sockaddr *)&csin, &csin_len)) != -1)
	{
		sv_new_cl_info(csin, sv->fds[i].sock);
		sv->fds[i].type = SK_CLIENT;
		sv->fds[i].ft_read = sv_receive_prepare;
		sv->fds[i].ft_write = sv_send_prepare;
		sv->max = max(sv->max, CL_SOCK(i));
	}
	else
		pterr(ERR_ACCEPT_FAILURE);
	printf("[valeur du sockfd client : %i]\n", sv->fds[i].sock);
}

void			sv_new_cl_info(struct sockaddr_in csin, int sock)
{
	ft_printf("[INFO][New client #%d from %s:%d]\n", sock,
		inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
}