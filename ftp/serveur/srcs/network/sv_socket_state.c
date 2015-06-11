#include <ftp_server.h>

void			sv_socket_state(t_sv_prop *sv)
{
	int		i;
	char	*str;
	char	skfr[] = "FREE";
	char	sksv[] = "SERVER";
	char	skcl[] = "CLIENT";

	i = 0;
	printf("%8s | %6s | %5s\n", "Number", "Type", "Fd value");
	while (i < MAX_SOCKETS)
	{
		if (sv->fds[i].type == SK_SERV)
			str = sksv;
		else if (sv->fds[i].type == SK_CLIENT)
			str = skcl;
		else
			str = skfr;
		printf("%8d | %6s | %5d\n", i, str, CL_SOCK(i));
		i++;
	}
}