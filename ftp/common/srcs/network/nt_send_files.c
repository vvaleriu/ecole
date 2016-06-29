#include <ftp_common.h>


/*
** On fait les verifications necessaires avant d'envoyer le fichier (droits, etc)
*/

static int		is_send_granted(int file_fd, struct stat *stat)
{
	if (fstat(file_fd, stat) == -1)
		return (-1);
	if (!(stat->st_mode & S_IROTH))
		return (-1);
	return (1);
}

/*
** cmda : lex the entered command to have all files that must be sent.
** then for each file :
** - prepare an send_info structure containing :
** the type of message sent: command (1)
** size of the command: ft_strlen(cl->gnl)
** no file name cause it is a command
** then if first send the structure and second the file itself
*/

static int		send_file_info(int sock, char *fname, struct stat stat)
{
	printf("[send_file_info]\n");
	nt_send_info(sock, T_BINARY, stat.st_size, fname);
	return (1);
}

static int		send_file(int sock, char *buf, int file_fd)
{
	int		rd;

	printf("[send_file]\n");
	while ((rd = read(file_fd, buf, BUF_SIZE - 1)) > 0)
		send(sock, buf, rd, 0);
	if (rd == -1)
	{
		printf("%s\n", "[ERR] [read error while trying to send the file]");
		return (rd);
	}
	return (1);
}
/*
static int		send_file(int sock, int file_fd, struct stat stat)
{
	int				wr;
	void			*file_addr;

	printf("[send_file]\n");
	file_addr = mmap(NULL, stat.st_size, PROT_READ, MAP_SHARED, file_fd, 0);
	wr = write(sock, file_addr, stat.st_size);
	if (wr == -1)
	{
		printf("%s\n", "[ERR] [read error while trying to send the file]");
		return (wr);
	}
	return (1);
}
*/
int				nt_send_files(char **files, int sock)
{
	int 		i;
	int			file_fd;
	struct stat	stat;

	i = 1;
	printf("[nt_send_files]\n");
	while (files[i])
	{
		if ((file_fd = open(files[i], O_RDONLY)) && is_send_granted(file_fd, &stat))
		{
			send_file_info(sock, files[i], stat);
			send_file(sock, files[i], file_fd);
			// send_file(sock, file_fd, stat);
			if (close(file_fd) == -1)
				printf("%s\n", "[ERR] [Closing file error]");
		}
		else
			printf("%s\n", ERR_FILE_NOT_FOUND);
		i++;
	}
	return (1);
}
