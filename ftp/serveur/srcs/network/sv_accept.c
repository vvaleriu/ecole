b#include <ftp_server.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

/*
** Create the server and accept client connection
*/

int			sv_accept(t_sv_prop *sv)
{
	int					i;
	struct sockaddr_in	csin;
	socklen_t			csin_len;
	
	i = 1;
	while (i < MAX_SOCKETS && sv->fds[i] != NULL)
		i++;
	if (i == MAX_SOCKETS)
	{
		pterr(ERR_MAX_CONNECTIONS);
		return (-1)
	}
//	if ((sv->fds[i].sock = accept(SV_SOCK, (struct sockaddr *)&csin, &csin_len)) == -1)
	if ((CL_SOCK(i) = accept(SV_SOCK, (struct sockaddr *)&csin, &csin_len)) == -1)
	{
		pterr(ERR_ACCEPT_FAILURE);
		return (-1)
	}
	sv->fds[i].type = SK_CLIENT;
	sv->max = max(sv->max, CL_SOCK(i));
	clean_fd(&(sv->fds[i]));
	return (1);
}
