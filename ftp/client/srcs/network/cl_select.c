#include <ftp_client.h>
#include <time.h>

void			cl_select(t_cl_prop *cl)
{
	int	ret;
	struct timeval timeout;

	timeout.tv_sec = 0;
	timeout.tv_usec = 100000;

	//ret = select(cl->max, &(cl->readfds), 0, 0, &timeout);
	ret = select(cl->max, &(cl->readfds), NULL, NULL, NULL);
	ft_printf("retour de select: %d\n", ret);
}