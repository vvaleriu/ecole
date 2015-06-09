#include <ftp_server.h>
#include <sys/select.h>

void				init_fds()
{
	int		i;

	i = 0;
	FD_ZERO(&(sv->readfds));
	FD_ZERO(&(sv->writefds));
	FD_SET(SV_SOCK, &(sv->writefds));
	while (i < MAX_SOCKETS && sv->fds[i] != NULL)
	{
		if
	}
}