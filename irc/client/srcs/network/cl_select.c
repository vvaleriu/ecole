#include <irc_client.h>
#include <time.h>

void			cl_select(t_cl_prop *cl)
{
	int	ret;

	ret = select(cl->max, &(cl->readfds), NULL, NULL, NULL);
	ft_printf("[select : %d]\n", ret);
}