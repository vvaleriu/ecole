#include <ftp_server.h>

void			read_client_input(t_sv_prop *sv)
{
	while (get_next_line(sv->cl.sock, &(sv->cmd)) > 0)
	{
		printf("%s\n", sv->cmd);
		sv->cmda = lexer(sv->cmd);
		//ft_putstr_array(sv->cmda);
		exe_command(sv);
	}
}
