#include <ftp_client.h>

void		cl_kill(t_cl_prop *cl, char **cmd)
{
	ft_strdel(cmd);
	close(cl->fd.sock);
	exit(2);
}