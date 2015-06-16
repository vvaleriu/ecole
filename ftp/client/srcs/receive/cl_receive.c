#include <ftp_client.h>

void			cl_receive(t_cl_prop *cl)
{
	int 	rd;

	while ((rd = E(-1, recv(SOCK, cl->fd.rd, BUF_SIZE, 0), ERR_RECV, NO_EXIT)) > 0)
	{
		cl->fd.rd[rd] = '\0';
		ft_printf("buf : %s\n", cl->fd.rd);
		ft_printf("nb rd :%d\n", rd);
	}
	/*if ((rd = E(-1, recv(SOCK, cl->fd.rd, BUF_SIZE, 0), ERR_RECV, NO_EXIT)) != -1)
	{
		ft_printf("on rentre dans cl_receive. Lu :%d (max)%d\n", rd, cl->max);
		ft_printf("reception :%s\n", cl->fd.rd);
	}*/
}