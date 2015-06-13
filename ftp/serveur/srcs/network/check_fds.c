#include <ftp_server.h>
#include <sys/select.h>

/*
**	Pour chaque fd, si celui ci appartient au set de lecture, on execute la fonction
**	correspondante, de meme pour l'ecriture, et enfin si on a traite qqc a propos de ce fd
**	alors on soustrait un au nombre de fd restant a traiter (left).
*/

void			check_fds(t_sv_prop *sv)
{
	int		i;

	i = 0;
	while (i < MAX_SOCKETS && sv->left > 0)
	{
		if (FD_ISSET(sv->fds[i].sock, &(sv->readfds)))
			sv->fds[i].ft_read(sv, i);
		if (FD_ISSET(sv->fds[i].sock, &(sv->writefds)))
			sv->fds[i].ft_write(sv, i);
		if (FD_ISSET(sv->fds[i].sock, &sv->readfds) || FD_ISSET(sv->fds[i].sock, &sv->writefds))
			sv->left--;
		i++;
	}
}