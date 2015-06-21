#include <ftp_client.h>
#include <netinet/in.h>
#include <sys/socket.h>

void				init_cl_prop(t_cl_prop *cl, char *ip, char *port)
{
	cl->gnl = NULL;
	cl->ip = ft_strdup(ip);
	ft_strdel(&(cl->ip));
	cl->ip = ft_strdup("127.0.0.1");
	cl->port = (unsigned short) ft_atoi(port);
	cl->fd.sock = 0;
	ft_bzero(cl->fd.rd, BUF_SIZE);
	ft_bzero(cl->fd.wr, BUF_SIZE);
}