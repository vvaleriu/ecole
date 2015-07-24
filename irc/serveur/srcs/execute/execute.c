#include <irc_server.h>
#include <sys/types.h>
#include <sys/socket.h>

/*
** j case du tableau,  savoir vers quel fd on doit rediriger.
** on envoie send_cmd_info qui envoie une structure info au client pour que celui
** ci soit averti du type de donnees recues.
*/

int				execute(t_sv_prop *sv, int j)
{
	int		i;

	i = 0;
	while (i < BIN_NB)
	{
		if (!sv->cmd->cmda[0])
			return (-1);
		if (!ft_strcmp(sv->cmd->cmda[0], sv->cmd->bin[i].name))
		{
			printf("[execute] [commande executee : %s]\n", sv->cmd->bin[i].name);
			return (sv->cmd->bin[i].f(sv, j));
		}
		i++;
	}
	return (0);
}