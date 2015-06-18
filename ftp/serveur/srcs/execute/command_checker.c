#include <ftp_server.h>
#include <sys/types.h>
#include <sys/socket.h>

/*
** j case du tableau,  savoir vers quel fd on doit rediriger.
*/

int				check_command(t_sv_prop *sv, j)
{
	int		i;

	i = 0;
	while (i < BIN_NB)
	{
		if (!sv->cmd->cmda[0])
			return (-1);
		if (ft_strcmp(sv->cmd->cmda[0], sv->cmd->bin[i].name))
			return (sv->cmd->bin[i].f(sv, j));
		i++;
	}
	return (0);
}