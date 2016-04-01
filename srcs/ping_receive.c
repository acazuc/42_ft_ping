/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_receive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 21:02:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/01 22:10:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void ping_receive(t_env *env)
{
	t_packet packet;
	struct timeval tv;
	ssize_t got;
	char buffer[500];

	tv.tv_sec = 50;
	tv.tv_usec = 0;
	if (setsockopt(env->socket, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(tv)) == -1)
	{
		ft_putendl_fd("ft_ping: can't set pakcet timeout", 2);
		exit(EXIT_FAILURE);
	}
	if ((got = recvfrom(env->socket, &packet, sizeof(packet), 0, NULL, NULL)) == -1)
	{
		ft_putendl_fd("ft_ping: can't receiving ping", 2);
		exit(EXIT_FAILURE);
	}
	ft_putnbr(got);
	ft_putstr(" bytes from ");
	if (!(inet_ntop(AF_INET, env->addr, buffer, sizeof(buffer))))
	{
		ft_putendl_fd("ft_ping: can't get host name", 2);
		exit(EXIT_FAILURE);
	}
	ft_putstr(buffer);
	ft_putstr(" (");
	ft_putstr(env->ip);
	ft_putstr("): icmp_req=");
	ft_putnbr(0);
	ft_putstr(" ttl=");
	ft_putnbr(0);
	ft_putstr(" time=");
	ft_putnbr(0);
	ft_putchar('\n');
}
