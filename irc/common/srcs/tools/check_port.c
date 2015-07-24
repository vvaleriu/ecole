#include <ftp_common.h>

void		check_port(char *port)
{
	if (ft_strlen(port) > 5)
		E(-1, -1, ERR_INVALID_PORT, FORCE_EXIT);
	while (*port)
	{
		if (!ft_isdigit(*port))
			E(-1, -1, ERR_INVALID_PORT, FORCE_EXIT);
		port++;
	}
}