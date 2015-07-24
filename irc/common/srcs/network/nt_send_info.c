#include <ftp_common.h>

/*
** Arg: type name and size of data to be transmit
*/

int			nt_send_info(int sock, int type, off_t size, char *name)
{
	int			ret;
	t_send_info	info;

	info.type = type;
	info.size = size;
	if (name)
		ft_strcpy(info.fname, name);
	else
		ft_bzero(info.fname, NAME_SIZE);
	ret = send(sock, &info, sizeof(info), 0);
	if (ret > 0)
		printf("[nt_send_info] [envoi info]\n");
	else
	{
		printf("[nt_send_info] [erreur envoi info ]\n");
		return (-1);
	}
	return (1);
}