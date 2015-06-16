#include <ftp_server.h>

void		ft_write(t_sv_prop *sv, int i)
{
	ft_printf("Un socket sur lequel ecrire: %d - %d.\n", i, sv->max);
}