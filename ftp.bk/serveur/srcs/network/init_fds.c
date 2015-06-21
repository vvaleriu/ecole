#include <ftp_server.h>
#include <sys/select.h>

/*
**	On ajoute aussi l'entree standard pour lire les
**	commandes serveur.
*/

void				init_fds(t_sv_prop *sv)
{
	int		i;

	i = 0;
	printf("init_fds\n");
	FD_ZERO(&(sv->readfds));
	FD_ZERO(&(sv->writefds));
	FD_SET(0, &(sv->readfds));
	while (i < MAX_SOCKETS)
	{
		if (sv->fds[i].type != SK_FREE)
		{
			FD_SET(CL_SOCK(i), &(sv->readfds));
			if (ft_strlen(sv->fds[i].wr) > 0)
				FD_SET(CL_SOCK(i), &(sv->writefds));
		}
		i++;
	}
	//sv_socket_state(sv, "init_fds");
}