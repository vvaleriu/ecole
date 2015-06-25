#include <ftp_client.h>

/*
** Check if this is just about sending the command or send a file
** using command "put"
** if the command starts by "put " we send the following file
** otherwise, we simply send a command.
*/

void		cl_send_prepare(t_cl_prop * cl)
{
	char	**files;

	printf("cl_send_prepare - [retour gnl : %d] [commande : %s]\n", get_next_line(0, &(cl->gnl)), cl->gnl);
	if (ft_strlen(cl->gnl))
	{
		if (!ft_strncmp(cl->gnl, "put ", 4))
		{
			files = lexer(cl->gnl);
			nt_send_files(files, SOCK);
			ft_strarray_del(&files);
		}
		else if (!is_client_side_command(cl, cl->gnl))
			nt_send_command(SOCK, cl->gnl);
	}
}
