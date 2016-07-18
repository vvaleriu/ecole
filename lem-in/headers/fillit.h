/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 23:17:16 by vincent           #+#    #+#             */
/*   Updated: 2016/07/17 01:59:37 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H_
# define _FILLIT_H_

# include <libft.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <fillit_errors.h>

/*
** FILLED : caracetere d'une case remplie
** EMPTY : caractere d'une case vide
** ---------
** RCOORD: coordonnees relatives des trois derniers points d'une case par
** rapport a la premiere
** P1_X: coordonnees x relatives du bloc 1 par rapport au x du bloc 0
** P1_Y: coordonnees y relatives du bloc 1 par rapport au y du bloc 0
** ...
** AP0_X: coordonnee X absolue du premier bloc de la piece
** AP0_Y: coordonnee Y absolue du premier bloc de la piece
** ---------
** X: coordonnees x de la map
** Y: coordonnees y de la map
** MSIZE: taille maximale du plan
** XYMAX: coordonnees maximales
** ---------
** XLEN: x len of the map
** YLAN: y len of the map
** LEN_MAX: longueur maximum de la solution en fonctino du nombre de
**			pieces recues
*/

# define FILLED		'#'
# define EMPTY		'.'
# define P1X		rcoord[0]
# define P1Y		rcoord[1]
# define P2X		rcoord[2]
# define P2Y		rcoord[3]
# define P3X		rcoord[4]
# define P3Y		rcoord[5]
# define AP0_X		rcoord[6]
# define AP0_Y		rcoord[7]
# define X			mcoord[0]
# define Y			mcoord[1]
# define MSIZE		52
# define XY_MAX		(MSIZE - 1)
# define XLEN		len[0]
# define YLEN		len[1]
# define LEN_MAX	inst->len_max

/*
** HELPERS pour map_len
*/
# define FIRST		sh[0]
# define LAST		sh[1]
# define MAX_X_LEN	sh[2]


# define XFIRST		sh[0]
# define XLAST		sh[1]
# define YFIRST		sh[2]
# define YLAST		sh[3]
# define EMPTY_LINE	sh[4]

/*
** - piece: tableau de 26 short contenant chacun le mappage d'un tetrimino
** de 16 cases sur les 16 bits du unsigned short
** - map: matrice contenant le carre de tetriminos
** - prcoord: array of array of short[8] containing each pieces relative
**				coordonates
** - len : longueur de la meilleure solution trouvee jusqu'a present
** - xlen: longeur des abscisses de de la meilleure solution trouvee jusqu'a present
** - ylen: longeur des ordonnees de de la meilleure solution trouvee jusqu'a present
** - len_max: longueur maximale du carre en fonction du nombre de pieces
**				recues en parametre
*/

typedef struct	s_fillit_inst
{
	unsigned short	piece_nb;
	unsigned short	piece[26];
	short			p_rcoord[26][8];
	unsigned short	len;
	unsigned short	xlen;
	unsigned short	ylen;
	unsigned short	len_max;
	char			**solution;
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
void				get_relative_coordonates(short rcoord[8], unsigned short piece);
void				print_map(char **map);
void				print_solution_map(char **map);
short				fit_on_map(t_fillit_inst *inst, char **map, unsigned short mcoord[2], unsigned short pnb);
unsigned short		map_len(t_fillit_inst *inst, char **map);
unsigned short		max(unsigned short a, unsigned short b);
short				main_recursion(t_fillit_inst *inst, char **map, unsigned short pnb);
void				user_valid(void);
void				delete_from_map(char **map, unsigned short mcoord[2], unsigned short pnb);


/*
** MAP TOOLS
*/

#endif