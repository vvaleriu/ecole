#include <ftp_server.h>

int				bin_pwd(t_sv_prop *sv, int i)
{
	char	*dir;

	dir = getcwd(NULL, BUF_CWD);
	dup2(CL_SOCK(i), 1);
	printf("%s\n", dir);
	ft_strdel(&dir);
	return (1);
}