#include <ftp_server.h>

int				check_command(t_sv_prop *sv)
{
	int		i;

	i = 0;
	while (i < BIN_NB)
	{
		if (ft_strcmp(sv->cmda[0], sv->bin[i]))
			return (1);
		i++;
	}
	return (0);
}