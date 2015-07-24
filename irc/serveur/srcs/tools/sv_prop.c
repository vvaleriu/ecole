#include <irc_server.h>

void		sv_prop(t_sv_prop *sv)
{
	int		i;

	i = 0;
	while (i < MAX_SOCKETS && sv->fds[i].type != SK_FREE)
		i++;
	printf("socket server: %d (%d clients connected)\n", SV_SOCK, i - 1);
}