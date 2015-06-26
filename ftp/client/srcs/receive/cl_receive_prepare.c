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
		printf("[cl_receive_prepare]\n");
		nt_display_send_info(info);
		if (info.type == T_OUTPUT)
			//cl_receive_output(cl, SOCK, cl->fd.rd, &info);
			cl_receive_output(cl);
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