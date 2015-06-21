#include <ftp_client.h>

void			cl_receive_files(t_cl_prop *cl)
{
	int 		rd;
	t_send_info info;

	printf("On rentre dans cl_receive_files.\n");
	if ((rd = E(-1, recv(SOCK, cl->fd.rd, BUF_SIZE, 0), ERR_RECV, NO_EXIT)) > 0)
	{
		cl->fd.rd[rd] = '\0';
		printf("Message recu : \n%s\n", cl->fd.rd);
	}
	else
	{
		cl_kill(cl);
		printf("%s\n", ERR_SV_CLOSED);
		exit(2);
	}
	ft_bzero(cl->fd.rd, ft_strlen(cl->fd.rd));
}

int 		read_file_info(t_cl_prop *cl, t_send_info *info)
{
	printf("On rentre dans read_file_info.\n");
	if ((rd = E(-1, recv(SOCK, info, sizeof(*info), 0), ERR_RECV, NO_EXIT)) > 0)
		printf("Received file info.%s\n");
	else
	{
		printf("%s\n", ERR_READ_FILE_INFO);
		return (-1);
	}
	return (1);
}

int			receive_file(t_cl_prop *cl, t_send_info *info)
{
	int		fd;

	printf("On rentre dans receice_file.\n");
	if ((fd = open(info.fname, O_RDWR | O_CREAT | O_EXCL)) > 0)
	{
		while ((rd = E(-1, recv(SOCK, cl->fd.rd, BUF_SIZE, 0), ERR_RECV, NO_EXIT)) > 0)
			write(fd, cl->fd.rd, rd);
		close(fd);
	}
	else
	{
		printf("%s\n", ERR_WRITE_FILE);
		return (-1);
	}
	return (1);
}