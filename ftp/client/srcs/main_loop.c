#include <ftp_client.h>
#include <sys/mman.h>
#include <sys/wait.h>

/*
**	1/ proc fils : on boucle sur la lecture des fds.
**	si on a recu qqc de get next line, alors on le copie dans le buffer
**	d'ecriture
** 	on continue la boucle
**
**	2/ proc pere : on boucle sur le get next line
**
**	line est partage entre les deux processus
*/

int 			main_loop(t_cl_prop *cl)
{
	while(1)
	{
		//printf("main_loop.\n");
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