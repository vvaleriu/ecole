#include <ftp_server.h>
#include <sys/types.h>
#include <sys/socket.h>

int				check_command(t_sv_prop *sv)
{
	int		i;

	i = 0;
	while (i < BIN_NB)
	{
		ft_printf("cmd: %s (%s)", sv->cmd->bin[i]);
		if (ft_strcmp(sv->cmd->cmda[0], sv->cmd->bin[i]))
			return (1);
		i++;
	}
	return (0);
}