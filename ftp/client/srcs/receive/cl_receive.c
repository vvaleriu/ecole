#include <ftp_client.h>

void			cl_receive(t_cl_prop *cl)
{
	int 	rd;

	if ((rd = E(-1, recv(SOCK, cl->fd.rd, BUF_SIZE, 0), ERR_RECV, NO_EXIT)) != -1)
		printf("on rentre dans cl_receive. Lu :%d (max)%d\n", rd, cl->max);
}