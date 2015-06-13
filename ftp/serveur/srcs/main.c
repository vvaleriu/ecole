#include <ftp_server.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <signal.h>

int					main(int ac, char **av, char **env)
{
	t_sv_prop		sv;

	usage(2, ac, av);
	init_sv_prop(&sv, av[1], env);
	if (sv_create(&sv) != -1)
		main_loop(&sv);
	sv_kill(&sv);
	return (0);
}

/*

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

** p->rd = -3 signifie qu'on a finit de le fichier mais que celui ce ne prend
** pas de \n final. On renvoit donc la chaine mais on met le marqueur a -3
** ce qui fait qu'a la prochaine entree on va quitter et renvoyer 0 directement


static int		e_o_f(t_str_prop *p, char **line)
{
	ft_strdel(&(p->buf));
	*line = p->file;
	if (ft_strlen(p->file))
	{
		p->rd = -3;
		return (1);
	}
	return (0);
}

int				gnl(int const fd, char **line)
{
	static t_str_prop	p = {-2, NULL, NULL, NULL, NULL};

	if (p.rd == -3)
		return (0);
	p.buf = (p.rd == -2 ? (char *)malloc(sizeof(char) * GNL_BUFFER + 1) : p.buf);
	if (fd < 0 || GNL_BUFFER < 1 || !p.buf)
		return (-1);
	ft_strdel(&p.tmp);
	while ((p.end = ft_strchr(p.file, '\n')) == NULL && p.rd != 0)
	{
		ft_bzero((void *)p.buf, GNL_BUFFER + 1);
		p.rd = read(fd, p.buf, GNL_BUFFER);
		if (!p.rd)
			return (e_o_f(&p, line));
		p.tmp = p.file;
		p.file = ft_strjoin(p.file, p.buf);
		ft_strdel(&p.tmp);
	}
	*p.end = '\0';
	*line = p.tmp = p.file;
	p.file = ft_strdup(p.end + 1);
	return (1);
}

int					main(int ac, char **av)
{
	//int fd;
	char *line;

	//if (ac != 2)
	//	exit(1);
	printf("%d: %s\n", ac, av[0]);
	//fd = open(0, O_RDWR);
	while (gnl(0, &line))
		printf("%s\n", line);
	free(line);
	printf("%s\n", "line freed");
	return (0);
}
*/