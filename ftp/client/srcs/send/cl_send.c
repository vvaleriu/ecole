#include <ftp_client.h>

void		cl_send(t_cl_prop * cl)
{
	char	*tmp;

	get_next_line(0, &tmp);
	ft_strcpy(cl->fd.wr, tmp);
	ft_strdel(&tmp);
	ft_printf("cl_send, message to be sent: %s\n", cl->fd.wr);
	if (ft_strlen(cl->fd.wr))
		send(cl->fd.sock, cl->fd.wr, ft_strlen(cl->fd.wr), 0);
	ft_bzero(cl->fd.wr, ft_strlen(cl->fd.wr));
}