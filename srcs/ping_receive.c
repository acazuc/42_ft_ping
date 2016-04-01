/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_receive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 21:02:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/01 21:09:12 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void ping_receive(t_env *env)
{
	t_packet packet;
	struct sockaddr addr;

	if (recvfrom(env->socket, &packet, sizeof(packet), 0, env->addr, env->addrlen) == -1)
	{
		ft_putendl("Failed while receiving ping", 2);
		exit(EXIT_FAILURE);
	}
}
