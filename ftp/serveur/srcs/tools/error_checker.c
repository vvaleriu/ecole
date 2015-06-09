#include <ftp_server.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*
**	Compares the results (res) to an error result (err) return by a function
**	if quit is != 0 then the program exits.
*/

int			err_int(int err, int res, char *str, int quit)
{
	if (err == res)
		printf("%s\n", str);
	if (quit)
		exit(2);
}

void		*err_void(void *err, void *res, char *str, int quit)
{
	if (res == err)
	{
		printf("%s\n", str);
		if (quit)
			exit(2);
	} 
	return (res);
}