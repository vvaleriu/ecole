#include <ftp_server.h>

void		main_loop(t_sv_prop *sv)
{
	while (1)
	{
		//printf("main_loop\n");
		init_fds(sv);
		sv->left = select(sv->max + 1, &(sv->readfds), &(sv->writefds), NULL, NULL);
		check_fds(sv);
	}
}