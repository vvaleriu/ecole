/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 23:17:16 by vincent           #+#    #+#             */
/*   Updated: 2016/07/09 00:23:18 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H_
# define _FILLIT_H_

# include <libft.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <fillit_errors.h>

# define USAGE	"you must provide at least one argument"
# define FILLED	'#'
# define EMPTY	'.'

/*
** cur_line_nb: number of the current line
** cur_line_pos: position of the current line (between 0 and 4, 0 - 3 means
	we're in as piece of the game, 4 is a separator)
** block_nb: number of block of the current piece
** prev_pos: position of the previous piece
*/

typedef struct	s_fillit_line
{
	int				cur_line_nb;
	unsigned short	cur_line_pos;
	unsigned short	block_nb;
	short			prev_pos;
}				t_fillit_line;


int		open_file(const char *filename);
int		assert_line(char *line);

#endif