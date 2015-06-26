#include <ftp_client.h>

/*
**	On receptionne les infos, on les affiche puis on nettoie les buffers
**
*/

int			cl_receive_output(t_cl_prop *cl)
{
	int 	rd;

	printf("[cl_receive_output]\n");
	if ((rd = E(-1, recv(SOCK, cl->fd.rd, BUF_SIZE, 0), ERR_RECV, NO_EXIT)) > 0)
	{
		cl->fd.rd[rd] = '\0';
		printf("[rd : %d][donnees recues :]\n%s\n", rd, cl->fd.rd);
	}
	else
	{
		cl_kill(cl);
		printf("%s\n", ERR_SV_CLOSED);
		exit(2);
	}
	wipe_fd(&(cl->fd));
	return (1);
}

/*
int			cl_receive_output(t_cl_prop *cl, int sock, char *buf, t_send_info *info)
{
	int 	rd;

	printf("[cl_receive_output]\n");
	nt_display_send_info(*info);
	//info->type = 0;
	if ((rd = E(-1, recv(sock, buf, BUF_SIZE, 0), ERR_RECV, NO_EXIT)) > 0)
	{
		buf[rd] = '\0';
		printf("[donnees recues :]\n%s\n", buf);
	}
	else
	{
		cl_kill(cl);
		printf("%s\n", ERR_SV_CLOSED);
		exit(2);
	}
	wipe_fd(&(cl->fd));
	return (1);
}
*/