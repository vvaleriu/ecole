#include <ftp_server.h>

void		ft_write(t_sv_prop *sv, int i)
{
	printf("Un socket sur lequel ecrire: %d - %d.\n", i, sv->max);
}