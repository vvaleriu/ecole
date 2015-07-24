#include <irc_server.h>

/*
** cl : case du tableau de sockets clients (= client)
**
*/

void				sv_send_prepare(t_sv_prop *sv, int cl)
{
	t_send_info 	info;
	int				rd;

	if ((rd = nt_receive_info(CL_SOCK(cl), &info)) != -1 && rd != 0)
	{
		if (info.type == T_COMMAND)
			sv_receive_command(sv, cl);
		else if (info.type == T_BINARY)
			nt_receive_files(CL_SOCK(cl), sv->fds[cl].rd, &info);
	}
	else
		clean_fd(&(sv->fds[cl]));
}
