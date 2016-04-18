/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graybaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 18:06:51 by graybaud          #+#    #+#             */
/*   Updated: 2016/04/02 18:47:35 by graybaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "main.h"

t_queue	*ft_init_queue(void)
{
	t_queue	*q;

	if (!(q = (t_queue *)malloc(sizeof(t_queue ))))
		return (NULL);
	q->size = 0;
	q->front = NULL;
	q->rear = NULL;
	return (q);
}

int		ft_queue_empty(t_queue *q)
{
	return (q->size == 0);
}

int		ft_enqueue(t_queue *q, char *s)
{
	t_queue_node	*node;
	t_queue_node	*tmp;

	if (!(node = (t_queue_node *)malloc(sizeof(t_queue_node))))
		return (0);
	node->next = NULL;
	tmp = node;
	if (s)
		node->token = ft_strdup(s);
	if (q->rear == NULL)
	{
		q->rear = node;
		q->front = node;
	}
	else
	{
		tmp = q->rear;
		q->rear = node;
		tmp->next = q->rear;
	}
	q->size++;
	return (1);
}

int		ft_dequeue(t_queue *q, char **s)
{
	t_queue_node	*t;

	t = q->front;
	if (ft_queue_empty(q))
		return (0);
	if (s)
		*s = ft_strdup(q->front->token);
	q->front = q->front->next;
	q->size--;
	free(t);
	return (1);
}

void	ft_print_queue(t_queue *q)
{
	t_queue_node *t;

	t = q->front;
	ft_printf("ft_print_queue()\n");
	while (t != NULL)
	{
		ft_printf("%s ", t->token);
		t = t->next;
	}
	ft_printf("\nend ft_print_queue()\n");
}
