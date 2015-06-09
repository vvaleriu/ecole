#include <ftp_server.h>
#include <sys/select.h>

void				init_fds(t_sv_prop *sv)
{
	int		i;

	i = 1;
	FD_ZERO(&(sv->readfds));
	FD_ZERO(&(sv->writefds));
	FD_SET(SV_SOCK, &(sv->readfds));
	while (i < MAX_SOCKETS)
	{
		if (sv->fds[i].type != SK_FREE)
		{
			FD_SET(CL_SOCK(i), &(sv->readfds));
			if (ft_strlen(sv->fds[i].write_b) > 0)
				FD_SET(CL_SOCK(i), &(sv->writefds));
		}
		i++;
	}
}