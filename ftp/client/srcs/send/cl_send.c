#include <ftp_client.h>

void		cl_send(t_cl_prop * cl)
{
	printf("valeur de rd : %d\n", get_next_line(0, &(cl->gnl)));
		if (ft_strlen(cl->gnl))
			send(cl->fd.sock, cl->gnl, ft_strlen(cl->gnl), 0);
}