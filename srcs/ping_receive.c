/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_receive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 21:02:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/02 18:05:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void ping_receive(t_env *env)
{
	t_packet packet;
	ssize_t got;
	size_t time;

	if ((got = recvfrom(env->socket, &packet, sizeof(packet), 0, env->addr, (socklen_t*)(&env->addrlen))) == -1)
	{
		ft_putendl_fd("ft_ping: can't receiving ping", 2);
		exit(EXIT_FAILURE);
	}
	ft_putendl("Received");
	time = epoch_micro() - env->last_send;
	got -= sizeof(packet.ip_header);
	if (packet.icmp_header.un.echo.id == getpid() && packet.icmp_header.un.echo.sequence == env->count/* && packet.icmp_header.type == ICMP_ECHOREPLY*/)
	{
		env->received++;
		if (!env->stopped)
			printf("%lu bytes from %s: icmp_seq=%d ttl=%d time=%3.3fms\n", got, env->ip, packet.icmp_header.un.echo.sequence, packet.ip_header.ttl, (time) / 1000.);
		time_add(env, time);
	}
}
