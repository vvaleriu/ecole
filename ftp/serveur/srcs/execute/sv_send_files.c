#include <ftp_server.h>

void		sv_send_files(t_sv_prop *sv, int i)
{
	printf("Un socket sur lequel ecrire: %d - %d.\n", i, sv->max);
}