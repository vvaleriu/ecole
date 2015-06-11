#include <ftp_server.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <stdlib.h>


/*int					main(int ac, char **av, char **env)
{
	t_sv_prop		sv;

	usage(ac, av);
	init_sv_prop(&sv, av[1], env);
	if (sv_create(&sv) != -1)
		main_loop(&sv);
	sv_kill(&sv);
	return (0);
}*/

int					main()
{
	char **ret;
	ret = ft_strsplit("SAluts les cocos j'ai un split qui marche ?", ' ');
	while (*ret != NULL)
	{
		printf("%s\n", *ret);
		ret++;
	}
	return (0);
}