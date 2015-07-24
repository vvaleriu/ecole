#include <irc_server.h>

int			bin_help(t_sv_prop *sv, int i)
{
	int		j;

	j = 0;
	if (dup2(CL_SOCK(i), 1))
	{
		printf("List of available commands:\n");
		while (j++ < BIN_NB)
			printf("%s\n", sv->cmd->bin[j++].name);
		return (1);
	}
	return (-1);
}