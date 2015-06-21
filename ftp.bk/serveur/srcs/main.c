#include <ftp_server.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <signal.h>

/*
**	on clean les sockets a partir de 1 (0 est le serveur) car sur certaines
**	initialisations le fds[i].sock vaut 13554534534 sans comprendre pourquoi
**	puis on rentre dans la boucle principale
*/

int					main(int ac, char **av, char **env)
{
	int				i;
	t_sv_prop		sv;

	i = 1;
	usage(2, ac, av);
	signal(SIGINT, sig_handler);
	init_sv_prop(&sv, av[1], env);
	if (sv_create(&sv) != -1)
	{
		while (i < MAX_SOCKETS)
			clean_fd(&(sv.fds[i++]));
		main_loop(&sv);
	}
	sv_kill(&sv);
	return (0);
}