#include <ftp_client.h>

void		check_fds(t_cl_prop *cl)
{
	if (FD_ISSET(SOCK, &(cl->readfds)))
	{
		ft_printf("On rrecoit des donnees sur le socket.\n");
		cl->fd.ft_read(cl);
	}
	if (FD_ISSET(0, &(cl->readfds)))
	{
		ft_printf("On a ecrit sur l'entree standard, on doit envoyer ces donnnes.\n");
		cl->fd.ft_write(cl);
	}
}

/*
void		check_fds(t_cl_prop *cl)
{
	//ft_printf("On rentre dans check_fds.\n");
	if (FD_ISSET(SOCK, &(cl->readfds)))
	{
	//	ft_printf("%s\n", "des choses a lire.\n");
		cl->fd.ft_read(cl);
	}
	//else
	//	ft_printf("%s\n", "rien a lire.\n");
	if (FD_ISSET(SOCK, &(cl->writefds)))
	{
		ft_printf("%s\n", "des choses a ecrire.\n");
		if (ft_strlen(cl->fd.wr))
			cl->fd.ft_write(cl);
	}
	else
		ft_printf("%s\n", "rien a ecrire.\n");
	if (ft_strlen(cl->fd.wr))
		cl->fd.ft_write(cl);
}
*/