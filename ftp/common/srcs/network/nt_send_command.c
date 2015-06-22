#include <ftp_common.h>

/*
** prepare an send_info structure containing :
** the type of message sent: command (1)
** size of the command: ft_strlen(cl->gnl)
** no file name cause it is a command
** then if first send the structure and second the command itself
*/

int		nt_send_command(int sock, char *com)
{
	t_send_info		info;

	info.type = T_COMMAND;
	info.size = ft_strlen(com);
	ft_bzero(info.fname, NAME_SIZE);
	nt_send_info(sock, &info);
	printf("Envoie de la command : %zu\n",
		send(sock, com, ft_strlen(com), 0));
	return (1);
}
