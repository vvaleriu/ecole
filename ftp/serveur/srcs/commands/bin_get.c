#include <ftp_server.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
** Receiving a get command means the server has to send all listed files
** sv->cmd->cmda[1] : on check qu'il y a au moins un argument (nom du
** fichier a envoyer)
*/

int			bin_get(t_sv_prop *sv, int cl)
{
	printf("On rentre dans get (envoie de fichier au client).\n");
	if (EV(NULL, sv->cmd->cmda[1], ERR_NO_FILE, NO_EXIT) == NULL)
	{
		err_no_file(sv, cl);
		return (-1);
	}
	else
		nt_send_files(sv->cmd->cmda, CL_SOCK(cl));
	return (1);
}

int			err_no_file(t_sv_prop *sv, int cl)
{
	dup2(CL_SOCK(cl), 1);
	printf("%s\n", ERR_NO_FILE);
	return (0);
}
