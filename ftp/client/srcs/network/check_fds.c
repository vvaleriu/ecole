#include <ftp_client.h>

void		check_fds(t_cl_prop *cl)
{
	if (FD_ISSET(SOCK, &(cl->readfds)))
	{
		printf("[check_fds - reception donnees]\n");
		cl->fd.ft_read(cl);
	}
	if (FD_ISSET(0, &(cl->readfds)))
	{
		printf("[check_fds - envoi de donnnes]\n");
		cl->fd.ft_write(cl);
	}
}