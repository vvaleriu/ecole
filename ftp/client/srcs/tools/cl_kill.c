#include <ftp_client.h>

void		sv_kill(t_cl_prop *cl)
{
	close(cl->fd.sock);
	ft_strdel(&cl->gnl);
}