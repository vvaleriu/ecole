/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 20:16:59 by vincent           #+#    #+#             */
/*   Updated: 2015/02/04 15:58:47 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_itoo(unsigned int n)
{
	unsigned int	oct;
	unsigned int	factor;

	oct = 0;
	factor = 1;
	while (n > 0)
	{
		oct += n % 8 * factor;
		n /= 8;
		factor *= 10;
	}
	return (oct);
}
