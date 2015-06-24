#include <ftp_common.h>



int			nt_receive_files(int sock, char *buf, t_send_info *info)
{
	int			fd;
	int			rd;
	long int	to_read;
	long int	already_read;

	already_read = 0;
	printf("[nt_receice_file]\n");
	if ((fd = open(info->fname, O_RDWR | O_CREAT | O_EXCL, 755)) > 0)
	{
		printf("[open success]\n");
		while (already_read < info->size)
		{
			to_read = ((long int)info->size - already_read >= BUF_SIZE ? BUF_SIZE : (long int)info->size - already_read);
			rd = E(-1, recv(sock, buf, to_read, 0), ERR_RECV, NO_EXIT);
			already_read += rd; 
			write(fd, buf, rd);
		}
		printf("[files sent to the socket] [fsize: %lu] [sent size: %lu]\n", info->size, already_read);
		close(fd);
		ft_bzero(buf, BUF_SIZE);
	}
	else
	{
		printf("%s\n", ERR_WRITE_FILE);
		return (-1);
	}
	return (1);
}


/*
int			nt_receive_files(int sock, char *buf, t_send_info *info)
{
	int		fd;
	int		rd;

	printf("nt_receice_file.\n");
	if ((fd = open(info->fname, O_RDWR | O_CREAT | O_EXCL, 755)) > 0)
	{
		printf("open success.\n");
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
*/