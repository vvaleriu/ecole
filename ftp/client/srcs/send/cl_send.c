#include <ftp_client.h>

void		cl_send(t_cl_prop * cl)
{
	if (ft_strlen(cl->fd.wr))
		send(cl->fd.sock, cl->fd.wr, ft_strlen(cl->fd.wr), 0);
	ft_bzero(cl->fd.wr, ft_strlen(cl->fd.wr));
}