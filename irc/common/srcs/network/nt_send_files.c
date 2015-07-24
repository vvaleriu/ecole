#include <ftp_common.h>

/*
** cmda : lex the entered command to have all files that must be sent.
** then for each file :
** - prepare an send_info structure containing :
** the type of message sent: command (1)
** size of the command: ft_strlen(cl->gnl)
** no file name cause it is a command
** then if first send the structure and second the file itself
*/

static int 		send_file_info(int sock, char *fname, int file_fd)
{
	struct stat		stat;

	printf("[send_file_info]\n");
	if (!fstat(file_fd, &stat))
		nt_send_info(sock, T_BINARY, stat.st_size, fname);
	else
	{
		printf("%s\n", "[ERR] [fstat error]");
		return (-1);
	}
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

int				nt_send_files(char **files, int sock)
{
	int 	i;
	int		file_fd;

	i = 1;
	printf("[nt_send_files]\n");
	while (files[i])
	{
		if ((file_fd = open(files[i], O_RDONLY)))
		{
			send_file_info(sock, files[i], file_fd);
			send_file(sock, files[i], file_fd);
			if (close(file_fd) == -1)
				printf("%s\n", "[ERR] [Closing file error]");
		}
		else
			printf("%s\n", ERR_FILE_NOT_FOUND);
		i++;
	}
	return (1);
}
