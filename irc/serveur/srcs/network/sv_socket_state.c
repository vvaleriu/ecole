#include <irc_server.h>

void			sv_socket_state(t_sv_prop *sv, char *tag)
{
	int		i;
	char	*str;
	char	skfr[] = "FREE";
	char	sksv[] = "SERVER";
	char	skcl[] = "CLIENT";

	i = 0;
	printf(" === from : %s , max: %d ===\n", tag, sv->max);
	printf("%5s | %6s | %5s | %6s | %6s\n", "Nb", "Type", "fd", "Read", "Write");
	while (i < MAX_SOCKETS)
	{
		if (sv->fds[i].type == SK_SERV)
			str = sksv;
		else if (sv->fds[i].type == SK_CLIENT)
			str = skcl;
		else
			str = skfr;
		printf("%5d | %6s | %5d | %6c | %6c\n", i, str, CL_SOCK(i),
			(FD_ISSET(CL_SOCK(i), &sv->readfds) ? 'X' : ' '),
			(FD_ISSET(CL_SOCK(i), &sv->writefds) ? 'X' : ' '));
		i++;
	}
}