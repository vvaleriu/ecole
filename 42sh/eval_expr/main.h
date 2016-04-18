/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:52:03 by graybaud          #+#    #+#             */
/*   Updated: 2016/04/02 18:52:48 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "struct.h"

int			ft_add(t_stack *top);
int			ft_sub(t_stack *top);
int			ft_divi(t_stack *top);
int			ft_mult(t_stack *top);
int			ft_is_operator(char c);
int			ft_is_number(char *s);
int			ft_is_digit(char c);
double		ft_atof(char *s);
int			ft_queue_empty(t_queue *q);
t_stack		*ft_init_stack(void);
t_queue		*ft_init_queue(void);
t_env		*ft_init_env(void);
char		**ft_init_matrice_char(int len);
int			ft_matrice_char_len(char **tab);
int			ft_enqueue(t_queue *q, char *s);
int			ft_dequeue(t_queue *q, char **s);
void		ft_print_queue(t_queue *q);
int			ft_stack_empty(t_stack *top);
int			ft_push_stack(t_stack *top, double nb, char *s);
int			ft_pop_stack(t_stack *top, double *nb, char **s);
void		ft_print_stack(t_stack *top);
void		ft_delete_stack(t_stack *top);
int			ft_read_token(char *token, t_stack *top);
int			ft_postfix(t_stack *top, char token);
void		ft_shunting_yard(t_env *env);
int			ft_get_precedence(char token);
void		ft_check_error(t_env *env);

#endif
