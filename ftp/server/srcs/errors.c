#include <ftp_server.h>

void			usage(char *binname, char *error)
{
	ft_printf("usage: %s %s\n", binname, error);
}

void			pterr(char *err)
{
		ft_printf("%s\n", err);
}