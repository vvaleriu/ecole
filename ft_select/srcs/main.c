/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 23:29:19 by vincent           #+#    #+#             */
/*   Updated: 2015/08/04 17:04:48 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int 		main(int ac, char **av)
{
	t_tconf	*conf;

	conf = get_instance();
	sig_catcher();
	if (ac < 2 || !av)
	{
		ft_printf("See usage.\n");
		return (0);
	}
	ft_putstr("\033[?1049h\033[H");
	init_terminal(conf);
	build_list(conf, ++av);
	print_list(conf);
	get_key(conf);
	return (0);
}
	
/*
static void		del(void *l, size_t lol)
{
	printf("On efface [%s] [taille:%zu]\n", (char*)l, lol);
}

static void		coco(t_dlist *el)
{
	char	*tmp;

	tmp = (char*)(el->content);
		printf("%s\n", tmp);
}

int 		main(int ac, char **av)
{
	t_dlist	*st;
	t_dlist	*el;

	st = NULL;
	printf("ac: %d\n", ac);
	el = ft_dlstnew(av[1], sizeof(char *));
	ft_dlstadd_last(&st, el);
	el = ft_dlstnew(av[2], sizeof(char *));
	ft_dlstadd_last(&st, el);
	el = ft_dlstnew(av[3], sizeof(char *));
	ft_dlstadd_last(&st, el);
	el = st;
	printf("Len: %d\n", ft_dlstlen(st));
	ft_dlstiter(st, coco);
	ft_dlstdelone(&st, st->next, del);
	ft_dlstiter(st, coco);
	ft_dlstdelone(&st, st->next, del);
	ft_dlstiter(st, coco);
	ft_dlstdelone(&st, st->next, del);
	ft_dlstiter(st, coco);

	printf("\n=====\n");
	el = ft_dlstnew(av[1], sizeof(char *));
	ft_dlstadd_last(&st, el);
	el = ft_dlstnew(av[2], sizeof(char *));
	ft_dlstadd_last(&st, el);
	el = ft_dlstnew(av[3], sizeof(char *));
	ft_dlstadd_last(&st, el);
	el = st;
	ft_dlstdel(&st, del);
	ft_dlstiter(st, coco);
	return 0;
}*/