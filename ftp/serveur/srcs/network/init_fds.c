#include <ftp_server.h>
#include <sys/select.h>

void				init_fds(t_sv_prop *sv)
{
	int		i;

	i = 0;
	FD_ZERO(&(sv->readfds));
	FD_ZERO(&(sv->writefds));
	sv_socket_state(sv);
	while (i < MAX_SOCKETS)
	{
		if (sv->fds[i].type != SK_FREE)
		{
			printf("%d (fd: %d): set in read.\n", i, sv->fds[i].sock);
			FD_SET(CL_SOCK(i), &(sv->readfds));
			if (ft_strlen(sv->fds[i].write_b) > 0)
			{
				printf("%d(fd: %d): set in write.\n", i, sv->fds[i].sock);
				FD_SET(CL_SOCK(i), &(sv->writefds));
			}
		}
		else
			printf("%d: empty slot\n", i);
		i++;
	}
}