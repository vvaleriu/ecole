#include <ftp_client.h>

int			cl_receive_output(t_cl_prop *cl, int sock, char *buf, t_send_info *info)
{
	int 	rd;

	printf("On rentre dans cl_receive_output.\n");
	nt_display_send_info(*info);
	if ((rd = E(-1, recv(sock, buf, BUF_SIZE - 1, 0), ERR_RECV, NO_EXIT)) > 0)
	{
		buf[rd] = '\0';
		printf("Message recu : \n%s\n", buf);
	}
	else
	{
		cl_kill(cl);
		printf("%s\n", ERR_SV_CLOSED);
		exit(2);
	}
	ft_bzero(buf, ft_strlen(cl->fd.rd));
	return (1);
}
