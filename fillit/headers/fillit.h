/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 23:17:16 by vincent           #+#    #+#             */
/*   Updated: 2016/07/12 15:39:38 by vincent          ###   ########.fr       */
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
** - piece: tableau de 26 short contenant chacun le mappage d'un tetrimino
** de 16 cases sur les 16 bits du unsigned short
** - map: matrice contenant le carre de tetriminos
*/

typedef struct	s_fillit_inst
{
	unsigned short	piece_nb;
	unsigned short	piece[26];
	char			map[52][52];
}				t_fillit_inst;

/*
** cur_line_nb: number of the current line
** cur_line_pos: position of the current line (between 0 and 4, 0 - 3 means
	we're in as piece of the game, 4 is a separator)
** block_nb: number of block of the current piece
** prev_pos: position of the previous piece
**
*/

typedef struct	s_fillit_line
{
	unsigned short	cur_line_nb;
	unsigned short	cur_line_pos;
	unsigned short	block_nb;
	short			prev_pos;
	t_fillit_inst	*inst;
}				t_fillit_line;

t_fillit_inst		*get_instance(void);
int					open_file(const char *filename);
int					get_line_info(char *line);

/*
** MAP TOOLS
*/

#endif