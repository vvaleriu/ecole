/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 23:17:16 by vincent           #+#    #+#             */
/*   Updated: 2016/07/26 12:40:35 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LEMIN_H_
# define _LEMIN_H_

# include <libft.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <lemin_errors.h>
# include <lemin_structs.h>

/*
** ====== PARSER ======
*/

int				read_entry(t_lemin_var *var);
int				parse(t_lemin_var *var, char *line);
int				parse_room(t_lemin_var *var, char **split, t_parser_info *pi);
int				parse_link(t_lemin_var *var, char **split);

/*
** ---- ASSERT ----
*/
int				is_room_name_correct(char *str);
int				is_digit_only(char *len);
int				are_rcoord_correct(char **split, int len);


/*
** ====== PATH ======
*/
int				deep_search(t_lemin_var *var, t_vertex *room, t_dlist **path);
int				width_search(t_lemin_var *var, t_vertex *room);

/*
** ====== PRINT ======
*/
void			print_mouv(t_lemin_var *var);

/*
** ====== ALGO ======
*/
int				algo(t_lemin_var *var);
/*
**  TOOLS
*/
t_lemin_var		*init();
t_vertex		*find_room_by_name(t_lemin_var *var, char *name);
int				is_part_of_final_path(t_fpath fpath, t_dlist *el);

/*
** DEBUG
*/

void			print_room_name(t_dlist *el);
void			print_room_dlist(t_dlist *el);
void			print_path(t_dlist *el);
void			clean(t_lemin_var *var);
void			print_ants(t_lemin_var *var);
void			print_all_paths(t_lemin_var *var);

#endif