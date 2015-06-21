#include <ftp_client.h>

void			nt_receive_output(int sock, char *buf, t_send_info info)
{
	int 	rd;

	printf("On rentre dans nt_receive_output.\n");
	if ((rd = E(-1, recv(sock, buf, (long int)info.size, 0), ERR_RECV, NO_EXIT)) > 0)
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
}