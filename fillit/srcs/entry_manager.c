/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 23:23:09 by vincent           #+#    #+#             */
/*   Updated: 2016/07/17 00:15:54 by vincent          ###   ########.fr       */
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
		get_line_info(line);
	E(-1, close(fd), CLOSE_FAILED, NO_EXIT);
	return (1);
}
