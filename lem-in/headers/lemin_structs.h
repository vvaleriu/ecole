/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 12:51:28 by vincent           #+#    #+#             */
/*   Updated: 2016/07/26 01:47:43 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_STRUCTS_H_
# define _LEMIN_STRUCTS_H_

# define RX		room->rcoord[0]
# define RY		room->rcoord[1]

/*
** n: nom de la piece
** rcoord: coordonnees de la piece
** lk_nb: nombre de liens de cette piece avec les autres pieces
** lks: chaine contenant le nom de chaque piece avec qui cette piece est liee
** father : utilise lors d'un parcours en largeur. Permet de sauvegarer le
**			sommet pere (c'est a dire celui par lequel on est arrive) du sommet
**			actuel
*/
typedef struct	s_vertex		t_vertex;

struct			s_vertex {
	char		*n;
	int			rcoord[2];
	int			lk_nb;
	int			tag;
	t_dlist		*lks;
	t_vertex	*father;
};

/*
** path: chemin de la liste des meilleurs chemin trouves que va emprunter
**		la fourmis
** nb:
*/
typedef struct s_ant
{
	t_dlist		*path;
	int			nb;
}				t_ant;

/*
** structure utilisee pour parser le fichier recu
*/
typedef struct	s_parser_info {
	int			is_start;
	int			is_end;
}				t_parser_info;

/*
** start: list contenant les pieces du chemin
** len : longueur du chemin
** diff : difference de longueur avec le meilleur chemin
*/
typedef struct	s_fpath
{
	t_dlist		*start;
	int			len;
	int			diff;
}				t_fpath;

/*
** ant_nb: nombre de fourmis
** room_nb: nombre de pieces / sommets
** rooms: liste de pieces
** lstart: maillon de la liste contenant la piece de depart
** lend: maillon de la liste contenant la piece d'arrivee
** paths: tableau de chemins que l'on va emprunter
** paths_nb: nombre de chemin dans le tableau du dessus
** start: piece de depart
** end: piece d'arrivee
*/
typedef struct	s_lemin_var {
	int			ant_nb;
	t_ant		*ants;
	int			room_nb;
	t_dlist		*rooms;
	t_dlist		*lstart;
	t_dlist		*lend;
	t_fpath		*paths;
	int			paths_nb;
	t_vertex	*start;
	t_vertex	*end;
}				t_lemin_var;

#endif