#include <ftp_server.h>
#include <sys/select.h>

void		select_fds(t_sv_prop *sv)
{
	sv->left = select(sv->max + 1, &(sv->readfds), &(sv->writefds), NULL, NULL);
}