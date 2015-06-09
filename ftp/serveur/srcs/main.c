#include <ftp_server.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <stdlib.h>

int					main(int ac, char **av, char **env)
{
	t_sv_prop		sv;

	if (ac != 2)
	{
		usage(av[0], ERR_USAGE);
		return (0);
	}
	init_sv_prop(&sv, av[1], env);
	if (sv_launch(&sv) != -1)
	{
		read_client_input(&sv);
		kill_server(&sv);
	}
	return (0);
}