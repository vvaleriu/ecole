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

/*
static void		input_loop(t_cl_prop *cl, char *line, char *tmp)
{
	while (get_next_line(0, &tmp) > 0)
	{
		if (!ft_strcmp(tmp, "exit") || !ft_strcmp(line, "exit"))
			cl_kill(cl, &tmp);
		ft_strcpy(line, tmp);
		printf("pere : %s\n", line);
	}
	ft_strdel(&tmp);
}

static void		transmission_loop(t_cl_prop *cl, char *line)
{
	while (1)
	{
		if (ft_strlen(line))
		{
			ft_strcpy(cl->fd.wr, line);
			ft_printf("fils: %s\n", cl->fd.wr);
			ft_bzero((void *)line, ft_strlen(line));
		}
		init_fds(cl);
		cl_select(cl);
		check_fds(cl);
	}
	munmap(line, sizeof(*line) * BUF_SIZE);
}

int 			main_loop(t_cl_prop *cl)
{
	char		*line;
	char 		*tmp;

	tmp = NULL;
	line = (char *)mmap(NULL, sizeof *line * BUF_SIZE, PROT_READ | PROT_WRITE,
									MAP_ANON | MAP_SHARED, -1, 0);

	if (fork())
		input_loop(cl, line, tmp);
	else
		transmission_loop(cl, line);
	return (1);
}
*/

int 			main_loop(t_cl_prop *cl)
{
	while(1)
	{
		init_fds(cl);
		cl_select(cl);
		check_fds(cl);
	}
	return (1);
}

/*
static void		input_loop(t_cl_prop *cl, char *line, char *tmp)
{
	//if (cl->max == 423423)
	//{
		while (get_next_line(0, &tmp) > 0)
		{
			if (!ft_strcmp(tmp, "exit") || !ft_strcmp(line, "exit"))
				cl_kill(cl, &tmp);
			ft_strcpy(line, tmp);
			printf("pere : %s\n", line);
		}
		ft_strdel(&tmp);
		printf("%s\n", "psps.");
	//}
}

static void		transmission_loop(t_cl_prop *cl, char *line)
{
	while (1)
	{
		if (ft_strlen(line))
		{
			ft_strcpy(cl->fd.wr, line);
			ft_printf("fils: %s\n", cl->fd.wr);
			ft_bzero((void *)line, ft_strlen(line));
		}
		init_fds(cl);
		cl_select(cl);
		check_fds(cl);
	}
	munmap(line, sizeof(*line) * BUF_SIZE);
}

int 			main_loop(t_cl_prop *cl)
{
	char		*line;
	char 		*tmp;

	tmp = NULL;
	line = (char *)mmap(NULL, sizeof *line * BUF_SIZE, PROT_READ | PROT_WRITE,
									MAP_ANON | MAP_SHARED, -1, 0);

	if (fork())
		input_loop(cl, line, tmp);
	else
		transmission_loop(cl, line);
	return (1);
}*/