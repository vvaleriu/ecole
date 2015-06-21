#include <ftp_server.h>
#include <sys/types.h>
#include <sys/socket.h>

/*
** cl : case du tableau de sockets clients (= client)
**
*/

void		sv_receive_prepare(t_sv_prop *sv, int cl)
{
	t_send_info 	info;
	int				rd;
	int				ret_cmd;

	if (nt_receive_info(CL_SOCK(cl), &info) != -1)
	{
		if (inf.type == T_COMMAND)
			sv_receive_command(sv, cl);
		else if (inf.type == T_BINARY)
			sv_receive_files(sv, cl);
	}
	else
		clean_fd(&(sv->fds[cl]));
}

int 		sv_receive_prepare(t_sv_prop *sv)
{

	if (nt_receive_info)
}