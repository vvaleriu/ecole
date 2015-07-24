#include <irc_server.h>

int			sv_send_message(int sock, char *mess)
{
	nt_send_info(sock, T_OUTPUT, ft_strlen(mess), NULL);
	if (dup2(sock, 1))
		printf("%s\n", mess);
	else
	{
		printf("[sv_send_message] [dup2 error]\n");
		return (-1);
	}
	return (1);
}