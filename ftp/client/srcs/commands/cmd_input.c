#include <ftp_client.h>

int		cmd_input(t_cl_prop * cl)
{
	char		*cmd;
	int			rd_ret;

	while ((rd_ret = get_next_line(0, &cmd)) != 0 && rd_ret != -1)
	{
		if (!ft_strcmp(cmd, "exit") || !ft_strcmp(cmd, "exit"))
			cl_kill(cl, cmd);
		ft_putstr_fd(cmd, cl->sock);
		printf("%s", cmd);
		ft_putstr_fd("ls -ln\n", cl->sock);
	}
	return (1);
}
