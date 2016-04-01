/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_send.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 13:30:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/01 21:26:01 by acazuc           ###   ########.fr       */
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
	env->sended = epoch_micro();
	ft_memcpy(packet.data, &env->sended, sizeof(env->sended));
	packet.chcksum = (uint16_t)ip_checksum(&packet, sizeof(packet));
	if (sendto(env->socket, &packet, sizeof(packet), 0, env->addr, env->addrlen) == -1)
	{
		ft_putendl_fd("ft_ping: can't send packet", 2);
		exit(EXIT_FAILURE);
	}
}
