#include <irc_client.h>

/*
** Check if this is just about sending the command or send a file
** using command "put"
** if the command starts by "put " we send the following file
** otherwise, if it's not a client side command, we simply send it to
** the server.
*/

void		cl_send_prepare(t_cl_prop * cl)
{
	char	**files;

	printf("[cl_send_prepare] [retour gnl : %d] | ", get_next_line(0, &(cl->gnl)));
	if (ft_strlen(cl->gnl))
	{
		if (!ft_strncmp(cl->gnl, "put ", 4))
		{
			printf("[envoi de fichier]\n");
			files = lexer(cl->gnl);
			nt_send_files(files, SOCK);
			ft_strarray_del(&files);
		}
		else if (!is_client_side_command(cl, cl->gnl))
		{
			printf("[envoi de commande server]\n");
			cl_send_command(cl);
		}
	}
}
