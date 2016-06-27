#include <ftp_client.h>
#include <sys/mman.h>
#include <sys/wait.h>

/*
**
*/

int 			main_loop(t_cl_prop *cl)
{
	while(1)
	{
		printf("===============================================================\n");
		init_fds(cl);
		cl_select(cl);
		check_fds(cl);
	}
	return (1);
}

/*
	tmp = NULL;
	line = (char *)mmap(NULL, sizeof *line * BUF_SIZE, PROT_READ | PROT_WRITE,
									MAP_ANON | MAP_SHARED, -1, 0);
	munmap(line, sizeof(*line) * BUF_SIZE);
}*/