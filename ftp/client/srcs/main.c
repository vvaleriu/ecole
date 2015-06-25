#include <ftp_client.h>
#include <netinet/in.h>
#include <sys/socket.h>

int					main(int ac, char **av, char **env)
{
	t_cl_prop		cl;

	usage(3, ac, av);
	init_cl_prop(&cl, av[1], av[2], env);
	cl_connect(&cl);
	main_loop(&cl);
	return (0);
}

