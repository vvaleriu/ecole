#include <ftp_server.h>
#include <sys/select.h>

/*
** On ajoute aussi l'entree standard pour lire les
** commandes serveur.
** 
**	FD_SET(0, &(sv->readfds)); = verifie si on a entre des choses sur
**			l'entree standard (= permet de recuperer des commandes)
** ------
** - On vide les ensembles de lecture et ecriture
** - Pour chaque socket :
**	* si le socket n'est pas libre, on l'ajoute a l'ensemble de lecture
** 	* s'il y a des choses dans son bufer d'ecriture, alors on le remet
**    dans l'ensemble d'ecriture
*/

void				init_fds(t_sv_prop *sv)
{
	int		i;

	i = 0;
	printf("[init_fds]\n");
	FD_ZERO(&(sv->readfds));
	FD_ZERO(&(sv->writefds));
	FD_SET(STDIN_FILENO, &(sv->readfds));
	while (i < MAX_SOCKETS)
	{
		if (sv->fds[i].type != SK_FREE)
		{
			FD_SET(CL_SOCK(i), &(sv->readfds));
			if (ft_strlen(sv->fds[i].wr) > 0)
				FD_SET(CL_SOCK(i), &(sv->writefds));
		}
		i++;
	}
}