#include <ftp_client.h>

/*
** prepare an send_info structure containing :
** the type of message sent: command (1)
** size of the command: ft_strlen(cl->gnl)
** no file name cause it is a command
** then if first send the structure and second the command itself
** and finally wipe all possible residual char in fd buffers (wipe_fd)
*/

void		cl_send_command(t_cl_prop *cl)
{
	printf("[cl_send_command] [gnl : %s]\n", cl->gnl);
	nt_send_info(SOCK, T_COMMAND, 0, cl->gnl);
	//printf("cl_send_command - [commande envoyee : %s] [octets envoyes : %zu]\n", cl->gnl,
	//	send(SOCK, cl->gnl, ft_strlen(cl->gnl), 0));
	send(SOCK, cl->gnl, ft_strlen(cl->gnl), 0);
	wipe_fd(&(cl->fd));
}
