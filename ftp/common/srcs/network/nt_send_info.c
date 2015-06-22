#include <ftp_common.h>

int			nt_send_info(int sock, t_send_info *info)
{
	int		ret;

	ret = send(sock, info, sizeof(*info), 0);
	if (ret > 0)
		printf("Reception des infos de transfert (send_type).\n");
	else
	{
		printf("Erreur reception des infos de transfert.\n");
		return (-1);
	}
	return (1);
}