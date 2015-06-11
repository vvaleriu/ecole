#include <ftp_server.h>

void		main_loop(t_sv_prop *sv)
{
	while (1)
	{
		init_fds(sv);
		printf("sv->max: %d\n", sv->max + 1);
		sv->left = select(sv->max + 1, &(sv->readfds), &(sv->writefds), NULL, NULL);
		check_fds(sv);
	}
}