#include <irc_server.h>

void			sv_socket_status(t_sv_prop *sv, int cl, char *tag)
{
	char	*str;
	char	skfr[] = "FREE";
	char	sksv[] = "SERVER";
	char	skcl[] = "CLIENT";

	if (sv->fds[cl].type == SK_SERV)
		str = sksv;
	else if (sv->fds[cl].type == SK_CLIENT)
		str = skcl;
	else
		str = skfr;
	printf("[%s] [client:%5d] [type: %6s] [fd: %5d] [read: %6c] [write: %6c]\n", tag, cl, str, CL_SOCK(cl),
		(FD_ISSET(CL_SOCK(cl), &sv->readfds) ? 'X' : ' '),
		(FD_ISSET(CL_SOCK(cl), &sv->writefds) ? 'X' : ' '));
}