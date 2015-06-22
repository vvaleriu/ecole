#include <ftp_server.h>
#include <sys/types.h>
#include <sys/socket.h>

/*
** cl : case du tableau de sockets clients (= client)
**
** - nt_receive_info envoie une structure info relative au transfert de donnees.
** - si le type est command, on on execute les fonctions relative a la reception
** 	de commande
** - si le type est binaire on lance simplement la reception de fichier
**
** On boucle jusqu'a temps que le sock soit vide, donc qu'il n'y ait rien
** a lire. C'est la fonction "nt_receive_info" qui renvoit 0 lorsque le socket
** est vide.
*/

void		sv_receive_prepare(t_sv_prop *sv, int cl)
{
	t_send_info 	info;
	int				ret_info;

	// A transformer en while
	if ((ret_info = nt_receive_info(CL_SOCK(cl), &info)) != -1 && ret_info != 0)
	{
		if (info.type == T_COMMAND)
			sv_receive_command(sv, cl);
		else if (info.type == T_BINARY)
			nt_receive_files(CL_SOCK(cl), sv->fds[cl].rd, &info);
	}
	else
		clean_fd(&(sv->fds[cl]));
}
