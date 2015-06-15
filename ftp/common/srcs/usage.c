#include <ftp_common.h>

void			usage(int target, int ac, char **av)
{
	if (ac != target)
	{
		printf("usage: %s %s\n", av[0], ERR_USAGE);
		exit(0);
	}
}