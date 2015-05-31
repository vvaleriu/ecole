#include <ftp_server.h>

/*void			read_client_input(t_sv_prop *sv)
{
	while (get_next_line(sv->cl.sock, &(sv->cmd)) > 0)
	{
		printf("%s", sv->cmd);
		exe_command(sv);
	}
}*/

void			read_client_input(t_sv_prop *sv)
{
	int 	nc;
	char	buf[1024];

	while ((nc = read(sv->cl.sock, buf, 1023)) > 0)
	{
		buf[nc] = '\0';
		printf("%s", buf);
	}
}

/*void			read_client_input(t_sv_prop *sv)
{
	int 	nc;
	char	buf[1024];

	while ((nc = read(sv->cl.sock, buf, 1023)) > 0)
	{
		buf[nc] = '\0';
		printf("%s", buf);
	}
}*/