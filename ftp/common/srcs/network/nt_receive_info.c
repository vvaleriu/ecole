#include <ftp_common.h>

int			nt_receive_info(int sock, t_send_info *info)
{
	int		ret;

	ret = recv(sock, info, sizeof(*info), 0);
	if (ret > 0)
	{
		printf("Reception des infos de transfert (send_type),\n");
		return (1);
	}
	else if (!ret)
	{
		printf("socket vide rien a revevoir\n");
		return (0);
	}
	printf("Erreur reception des infos de transfert.\n");
	return (-1);
}