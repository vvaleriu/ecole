#include <ftp_client.h>

void			cl_receive(t_cl_prop *cl)
{
	int 	rd;

	if ((rd = E(-1, recv(SOCK, cl->fd.rd, BUF_SIZE, 0), ERR_RECV, NO_EXIT)) > 0)
	{
		cl->fd.rd[rd] = '\0';
		printf("Message recu : \n%s\n", cl->fd.rd);
	}
	ft_bzero(cl->fd.rd, ft_strlen(cl->fd.rd));
}