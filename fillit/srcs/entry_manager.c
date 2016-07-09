/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 23:23:09 by vincent           #+#    #+#             */
/*   Updated: 2016/07/09 00:07:08 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		open_file(const char *filename)
{
	int		fd;
	char	*line;

	line = NULL;
	E(-1, (fd = open(filename, O_RDONLY)), OPEN_FAILED, FORCE_EXIT);
	while (get_next_line(fd, &line))
	{
		ft_printf("line: %s\n", line);
		assert_line(line);
	}
	E(-1, close(fd), CLOSE_FAILED, NO_EXIT);
	return (1);
}
