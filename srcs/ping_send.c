/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_send.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 13:30:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/01 21:10:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void ping_send(t_env *env)
{
	t_packet packet;

	ft_bzero(&packet, sizeof(packet));
	packet.type = ICMP_ECHO;
	packet.code = 0;
	packet.id = getpid();
	packet.sequence = 1;
	packet.chcksum = (uint16_t)ip_checksum(&packet, sizeof(packet));
	if (sendto(env->socket, &packet, sizeof(packet), 0, env->addr, env->addrlen) == -1)
	{
		ft_putendl_fd("Failed to send packet", 2);
	}
}
