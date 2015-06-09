#include <ftp_server.h>

void			usage(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("usage: %s %s\n", av[0], ERR_USAGE);
		exit(0);
	}
}