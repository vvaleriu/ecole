#include <ftp_client.h>

/*
** cmda : lex the entered command to have all files that must be sent.
** then for each file :
** - prepare an send_info structure containing :
** the type of message sent: command (1)
** size of the command: ft_strlen(cl->gnl)
** no file name cause it is a command
** then if first send the structure and second the file itself
*/

void		nt_send_files(char **files, int sock)
{
	int 	i;
	int		file_fd;

	i = 1;
	while (files[i])
	{
		if (file_fd = open(files[i], O_RDONLY))
		{
			send_file_info(sock, files[i], file_fd);
			send_file(sock, files[i]);
			if (close(file_fd) == -1)
				printf("%s\n", "Closing file error.");
		}
		else
			printf("%s\n", ERR_FILE_NOT_FOUND);
		i++;
	}
}

int 	send_file_info(int sock, char *fname, int file_fd)
{
	t_send_info		info;
	struct stat		fstat;

	if (fstat(file_fd, *fstat) > 0)
	{ 
		info.type = T_BINARY;
		info.size = fstat.st_size;
		ft_strcpy(info.fname, fname);
		nt_send_info(sock, &info);
	}
	else
	{
		printf("%s\n", "fstat error.");
		return (-1)
	}
	return (1);
}

int		send_file(int sock, char *buf, int file_fd)
{
	int		rd;

	while ((rd = read(file_fd, buf, BUF_SIZE - 1)) > 0)
		send(sock, buf, rd, 0);
	if (rd == -1)
	{
		printf("%s\n", "read error while trying to send the file.");
		return (rd);
	}
	return (1);
}