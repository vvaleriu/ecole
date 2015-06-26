#include <ftp_server.h>

int				bin_pwd(t_sv_prop *sv, int i)
{
	char	*dir;

	dir = getcwd(NULL, BUF_CWD);
	sv_send_message(CL_SOCK(i), dir);
	ft_strdel(&dir);
	return (1);
}