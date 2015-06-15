#include <ftp_client.h>

void			cl_select(t_cl_prop *cl)
{
	select(cl->max, &cl->readfds, NULL, NULL, NULL);
}