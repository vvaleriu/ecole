#include <ftp_client.h>
#include <netinet/in.h>
#include <sys/socket.h>

void				init_cl_prop(t_cl_prop *cl, char *ip, char *port)
{
	cl->max = 0;
	cl->gnl = NULL;
	cl->ip = ft_strdup(ip);
	check_port(port);
	cl->port = (unsigned short) ft_atoi(port);
	clean_fd(&(cl->fd));
	cl->fd.type = SK_CLIENT;
}