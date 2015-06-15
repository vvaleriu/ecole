#include <ftp_client.h>

int		cmd_input(t_cl_prop * cl)
{
	int		rd;
	char	*line;

	while ((rd = get_next_line(0, &line)) > 0)
	{
		//printf("%s\n", line);
		if (!ft_strcmp(line, "exit") || !ft_strcmp(line, "exit"))
			cl_kill(cl, &line);
		send(cl->fd.sock, (void *)line, ft_strlen(line), 0);
	}
	ft_strdel(&line);
	return (1);
}

/*
int		cmd_input(t_cl_prop * cl)
{
	int		rd;
	char	*line;

	while ((rd = get_next_line(0, &line)) > 0)
	{
		//printf("%s\n", line);
		if (!ft_strcmp(line, "exit") || !ft_strcmp(line, "exit"))
			cl_kill(cl, &line);
		send(cl->fd.sock, (void *)line, ft_strlen(line), 0);
	}
	ft_strdel(&line);
	return (1);
}
*/