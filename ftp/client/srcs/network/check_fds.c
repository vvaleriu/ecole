#include <ftp_client.h>

void		check_fds(t_cl_prop *cl)
{
	if (FD_ISSET(SOCK, &(cl->readfds)))
	{
		printf("Reception donnees sur le socket.\n");
		cl->fd.ft_read(cl);
	}
	if (FD_ISSET(0, &(cl->readfds)))
	{
		printf("Texte sur entree standard, envoyer ces donnnes.\n");
		cl->fd.ft_write(cl);
	}
}