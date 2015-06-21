#include <ftp_server.h>

int			bin_put(t_sv_prop *sv, int cl)
{
	dup2(CL_SOCK(cl), 1);
	printf("%s\n", "On envoit le fichier.");
	return (1);
}