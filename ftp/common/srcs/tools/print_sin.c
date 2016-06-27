/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaleriu <vvaleriu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 13:51:49 by vvaleriu          #+#    #+#             */
/*   Updated: 2016/06/27 14:13:29 by vvaleriu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftp_common.h>

void 	print_sin(struct sockaddr_in sin)
{
	printf("ip: %s\n", inet_ntoa(sin.sin_addr));
	printf("port: %d\n", sin.sin_port);
	printf("ai-familiy: : %d\n", sin.sin_family);
}