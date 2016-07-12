/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 23:23:09 by vincent           #+#    #+#             */
/*   Updated: 2016/07/12 16:04:09 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int			open_file(const char *filename)
{
	int		fd;
	char	*line;

	line = NULL;
	E(-1, (fd = open(filename, O_RDONLY)), OPEN_FAILED, FORCE_EXIT);
	while (get_next_line(fd, &line))
	{
		ft_printf("line: %s\n", line);
		get_line_info(line);
	}
	get_instance()->piece_nb++;
	E(-1, close(fd), CLOSE_FAILED, NO_EXIT);
	return (1);
}
