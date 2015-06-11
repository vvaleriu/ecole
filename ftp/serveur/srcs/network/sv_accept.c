#include <ftp_server.h>
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
	else if ((CL_SOCK(i) = accept(SV_SOCK, (struct sockaddr *)&csin, &csin_len)) != -1)
	{
		printf("New client #%d from %s:%d\n", i, inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
		clean_fd(&(sv->fds[i]));
		sv->fds[i].type = SK_CLIENT;
		sv->fds[i].ft_read = ft_read;
		sv->fds[i].ft_write = ft_write;
		sv->max = max(sv->max, CL_SOCK(i));
	}
	else
		pterr(ERR_ACCEPT_FAILURE);
}

void			sv_new_cl_info(struct sockaddr_in csin, int i)
{
	printf("New client #%d from %s:%d\n", i,
	inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
}