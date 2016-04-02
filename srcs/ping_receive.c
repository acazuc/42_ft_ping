/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_receive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 21:02:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/02 15:54:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static float gettimediff(t_packet *packet)
{
	struct timeval *sended;
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
	{
		ft_putendl_fd("ft_ping: can't get timeval", 2);
		exit(EXIT_FAILURE);
	}
	sended = (struct timeval*)packet->data;
	return (((tv.tv_sec * 1000.) + (tv.tv_usec / 1000.)) - ((sended->tv_sec * 1000.) + (sended->tv_usec / 1000.)));
}

void ping_receive(t_env *env, t_packet content)
{
	t_packet packet;
	ssize_t got;

	if ((got = recvfrom(env->socket, &packet, sizeof(packet), 0, env->addr, (socklen_t*)&env->addrlen)) == -1)
	{
		ft_putendl_fd("ft_ping: can't receiving ping", 2);
		exit(EXIT_FAILURE);
	}
	got -= sizeof(packet.ip_header);
	env->received++;
	if (!env->stopped)
		printf("%lu bytes from %s: icmp_seq=%d ttl=%d time=%3.3fms\n", got, env->ip, packet.icmp_header.un.echo.sequence, packet.ip_header.ttl, gettimediff(&content));
}
