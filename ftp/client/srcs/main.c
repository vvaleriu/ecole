#include <ftp_client.h>
#include <netinet/in.h>
#include <sys/socket.h>

int					main(int ac, char **av)
{
	t_cl_prop		cl;

	if (ac != 3)
	{
		usage(av[0], ERR_USAGE);
		return (0);
	}
	init_cl_prop(&cl, av[1], av[2]);
	cl_connect(&cl);
	//write(cl.sock, "ls -l\n", 11);
	cmd_input(&cl);
	//close(cl.sock);
	return (0);
}
