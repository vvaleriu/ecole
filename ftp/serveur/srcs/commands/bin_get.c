#include <ftp_server.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
** i = 1 : on check qu'il y a au moins un argument (nom du fichier a envoyer)
*/

int			bin_get(t_sv_prop *sv, int cl)
{
	int		i;

	i = 1;
	printf("On rentre dans get.\n");
	if (EV(NULL, sv->cmd->cmda[i], ERR_NO_FILE, NO_EXIT) == NULL)
		return (-1);
	while (sv->cmd->cmda[i])
	{
		send_file(sv, sv->cmd->cmda[i], cl);
		i++;
	}
	return (1);
}

int			send_file(t_sv_prop *sv, char *filename, int cl)
{
	int		file_fd;
	//int		rd;

	if ((file_fd = open(filename, O_RDONLY)))
		/*while ((rd = read(file, sv->fds[cl].wr, BUF_SIZE)))
		{
			//send(CL_SOCK(cl), sv->fds[cl].wr, BUF_SIZE, );

		}*/
		send_file_info(sv, filename, file_fd, cl);
	return (1);
}

int			send_file_info(t_sv_prop *sv, char *fname, int file_fd, int cl)
{
	struct stat		stat;

	if (fstat(file_fd, &stat))
	{
		//send(CL_SOCK(cl), sv->fds[i].wr, BUF_SIZE, );
		dup2(CL_SOCK(cl), 1);
		printf("[nom : %s] [taille : %lld octets]\n", fname, (long long int)stat.st_size);
	}
	return (1);
}

int			err_no_file(t_sv_prop *sv, int cl)
{
	dup2(CL_SOCK(cl), 1);
	printf("%s\n", ERR_NO_FILE);
	return (0);
}
