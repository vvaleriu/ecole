#include <ftp_common.h>

int			nt_receive_info(int sock, t_send_info *info)
{
	int		ret;

	ret = recv(sock, info, sizeof(*info), 0);
	if (ret > 0)
	{
		printf("[nt_receive_info] [reception OK] [taille lue: %d] (taille struct info : %lu)\n", ret, sizeof(*info));
		return (1);
	}
	else if (!ret)
	{
		printf("[nt_receive_info] [socket vide rien a revevoir]\n");
		return (0);
	}
	printf("[nt_receive_info] [reception ERR]\n");
	return (-1);
}