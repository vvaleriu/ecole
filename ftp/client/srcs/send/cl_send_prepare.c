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

	printf("valeur de rd : %d\n", get_next_line(0, &(cl->gnl)));
	if (ft_strlen(cl->gnl))
		if (!ft_strncmp(cl->gnl, "put "))
		{
			files = lexer(cl->gnl);
			nt_send_file(files, sock);
			ft_strarray_del(&files);
		}
		else
			nt_send_command(SOCK, cl->gnl);
}
