#include <ftp_client.h>

/*
**	On remets les deux set a zero.
** 	On met le socket dans le set de lecture pour voir si on a recu des choses
**	On met le socket en ecriture s'il y a des choses dans le buffer d'ecriture
*/

void			init_fds(t_cl_prop *cl)
{
	ft_printf("%s\n", "On rentre dans init_fds");
	FD_ZERO(&cl->readfds);
	FD_SET(SOCK, &cl->readfds);
	FD_SET(0, &cl->readfds);
}
