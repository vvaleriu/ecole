#include <ftp_client.h>

void		check_fds(t_cl_prop *cl)
{
	if (FD_ISSET(SOCK, &(cl->readfds)))
	{
		printf("%s\n", "des choses a lire.\n");
		cl->fd.ft_read(cl);
	}
	else
		printf("%s\n", "rien a lire.\n");
	/*if (FD_ISSET(SOCK, &(cl->writefds)))
		cl->fd.ft_write(cl);*/
	if (ft_strlen(cl->fd.wr))
		cl->fd.ft_write(cl);
}