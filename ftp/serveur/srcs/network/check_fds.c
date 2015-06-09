#include <ftp_server.h>
#include <sys/select.h>

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
	}
}