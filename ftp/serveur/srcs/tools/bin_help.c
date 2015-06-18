#include <ftp_server.h>

int			sv_help(t_sv_prop *sv)
{
	int		i;

	i = 0;
	printf("List of available commands:\n");
	while (i < BIN_NB)
	{
		printf("%s\n", sv->cmd->bin[i].name);
	}
	return (1);
}