/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 18:53:17 by graybaud          #+#    #+#             */
/*   Updated: 2016/04/02 18:53:18 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_stack_node	t_stack_node;
typedef struct s_stack		t_stack;
typedef struct s_queue_node	t_queue_node;
typedef struct s_queue		t_queue;
typedef struct s_expr		t_expr;
typedef struct s_env		t_env;
typedef	int					(*t_ope)(t_stack *);

struct						s_expr
{
	char			c;
	t_ope			ft_operation;
};

struct						s_stack_node
{
	double			nb;
	char			*str;
	t_stack_node	*next;
};

struct						s_stack
{
	t_stack_node	*top;
	int				size;
};

struct						s_queue_node
{
	char			*token;
	t_queue_node	*next;
};

struct						s_queue
{
	t_queue_node	*front;
	t_queue_node	*rear;
	int				size;
};

struct						s_env
{
	int				i;
	char			*token;
	char			**arg;
	t_stack			*stack;
	t_queue			*queue;
};

#endif
