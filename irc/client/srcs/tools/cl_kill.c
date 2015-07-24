#include <irc_client.h>

void		cl_kill(t_cl_prop *cl)
{
	close(cl->fd.sock);
	ft_strdel(&cl->gnl);
	ft_strdel(&cl->ip);
	ft_strarray_del(&cl->path);
}