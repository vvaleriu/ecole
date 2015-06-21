#include <ftp_client.h>
 
/*
**	On lit dans le buffer la taille d'une structure info pour savoir quel type
**	de donnees (binaire / output) nous devons traiter sur le serveur
*/

void			cl_receive_prepare(t_cl_prop *cl)
{
	int 		rd;
	t_send_info	info;

	if ((rd = E(-1, recv(SOCK, &info, sizeof(info), 0), ERR_RECV, NO_EXIT)) > 0)
	{
		if (info.type == T_OUTPUT)
			nt_receive_output(SOCK, cl->fd.rd, &info);
		else if (info.type == T_BINARY)
			nt_receive_files(SOCK, cl->fd.rd, &info);
	}
	else
	{
		cl_kill(cl);
		printf("%s\n", ERR_SV_CLOSED);
		exit(2);
	}
}