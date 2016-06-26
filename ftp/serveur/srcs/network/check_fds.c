#include <ftp_server.h>
#include <sys/select.h>

/*
**	Pour chaque fd ouvert, si celui ci appartient au set de lecture, on execute la fonction
**	correspondante, de meme pour l'ecriture, et enfin si on a traite qqc a propos de ce fd
**	alors on soustrait un au nombre de fd restant a traiter (left).
*/

void			check_fds(t_sv_prop *sv)
{
	int		i;

	i = 0;
	printf("[check_fds]\n");
	if (FD_ISSET(STDIN_FILENO, &(sv->readfds)))
	{
		execute_sv(sv);
		sv->left--;
	}
	while (i < MAX_SOCKETS && sv->left > 0)
	{
		//sv_socket_status(sv, i, "check_fds");
		if (sv->fds[i].type != SK_FREE && FD_ISSET(sv->fds[i].sock, &(sv->readfds)))
		{
			if (sv->fds[i].ft_read)
				sv->fds[i].ft_read(sv, i);
			else
				printf("[ERR] [slot %d, is set to read but read function null]\n", i);
		}
		//if (FD_ISSET(sv->fds[i].sock, &(sv->writefds)))
			//sv->fds[i].ft_write(sv, i);
		if (FD_ISSET(sv->fds[i].sock, &sv->readfds) /*|| FD_ISSET(sv->fds[i].sock, &sv->writefds)*/)
			sv->left--;
		i++;
	}
}