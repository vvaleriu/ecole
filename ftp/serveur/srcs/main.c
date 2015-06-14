#include <ftp_server.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <signal.h>

int					main(int ac, char **av, char **env)
{
	t_sv_prop		sv;

	usage(2, ac, av);
	init_sv_prop(&sv, av[1], env);
	if (sv_create(&sv) != -1)
		main_loop(&sv);
	sv_kill(&sv);
	return (0);
}