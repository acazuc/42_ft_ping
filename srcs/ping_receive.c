/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_receive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 21:02:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/13 12:51:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void ping_receive(t_env *env)
{
	t_packet packet;
	ssize_t got;
	size_t time;
	char ip[16];

	if ((got = recvfrom(env->socket, &packet, sizeof(packet), 0, NULL, NULL)) == -1)
	{
		ft_putendl_fd("ft_ping: can't receiving ping", 2);
		exit(EXIT_FAILURE);
	}
	time = epoch_micro() - env->last_send;
	got -= sizeof(packet.ip_header);
	ft_bzero(ip, 16);
	if (packet.icmp_header.un.echo.id == getpid() && packet.icmp_header.un.echo.sequence == env->count && packet.icmp_header.type == ICMP_ECHOREPLY)
	{
		env->has_received = 1;
		env->received++;
		if (!env->stopped)
			printf("%lu bytes from %s: icmp_seq=%d ttl=%d time=%3.3fms\n", got, inet_ntop(AF_INET, &packet.ip_header.saddr, ip, 16), packet.icmp_header.un.echo.sequence, packet.ip_header.ttl, (time) / 1000.);
		time_add(env, time);
	}
	else if (env->v)
	{
		if (packet.icmp_header.type == 3 || packet.icmp_header.type == 11 || packet.icmp_header.type == 12)
		{
			if (!env->stopped)
				printf("%lu bytes from %s: type=%d code=%d\n", got, inet_ntop(AF_INET, &packet.ip_header.saddr, ip, 16), packet.icmp_header.type, packet.icmp_header.code);
		}
	}
}
