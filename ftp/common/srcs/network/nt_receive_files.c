#include <ftp_client.h>

void			nt_receive_files(int sock, char *buf, t_send_info *info)
{
	int		fd;

	printf("On rentre dans receice_file.\n");
	if ((fd = open(info->fname, O_RDWR | O_CREAT | O_EXCL)) > 0)
	{
		while ((rd = E(-1, recv(sock, buf, BUF_SIZE, 0), ERR_RECV, NO_EXIT)) > 0)
			write(fd, buf, rd);
		close(fd);
	}
	else
	{
		printf("%s\n", ERR_WRITE_FILE);
		return (-1);
	}
	return (1);
}
