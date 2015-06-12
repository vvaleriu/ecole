/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smerieux <smerieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 11:42:32 by smerieux          #+#    #+#             */
/*   Updated: 2015/01/28 16:18:08 by smerieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <libft.h>

# define BUFF_SIZE 8

int			get_next_line(int const fd, char **line);
void		ft_readline(int const fd, int *ret, char **buff, char **tmp);
void		*ft_resize(void *ptr, size_t n);

#endif
