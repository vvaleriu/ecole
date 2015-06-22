#include <ftp_client.h>

/*
** prepare an send_info structure containing :
** the type of message sent: command (1)
** size of the command: ft_strlen(cl->gnl)
** no file name cause it is a command
** then if first send the structure and second the command itself
*/

void		cl_send_command(t_cl_prop *cl)
{
	t_send_info		info;

	info.type = T_COMMAND;
	info.size = ft_strlen(cl->gnl);
	ft_bzero(info.fname, NAME_SIZE);
	nt_send_info(SOCK, &info);
	printf("Envoie de la command : %zu\n",
		send(SOCK, cl->gnl, ft_strlen(cl->gnl), 0));
}
