/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_send.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 13:30:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/02 18:28:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static void build_ip_header(t_env *env, struct iphdr *header)
{
	ft_bzero(header, sizeof(*header));
	header->version = 4;
	header->ihl = 5;
	header->tos = 0;
	header->tot_len = sizeof(t_packet);
	header->id = ICMP_ECHO;
	header->frag_off = 2 << 13;
	header->ttl = 255;
	header->protocol = IPPROTO_ICMP;
	header->check = 0;
	if (inet_pton(AF_INET, env->ip, &header->daddr) != 1)
	{
		ft_putendl_fd("ft_ping: can't pton ip", 2);
		exit(EXIT_FAILURE);
	}
	header->saddr = 0;
	header->check = 0;
}

static void build_icmp_header(t_env *env, struct icmphdr *header)
{
	ft_bzero(header, sizeof(*header));
	header->type = ICMP_ECHO;
	header->code = 0;
	header->un.echo.id = getpid();
	header->un.echo.sequence = env->count;
	header->checksum = 0;
	header->checksum = ip_checksum(header, sizeof(*header));
}

void ping_send(t_env *env)
{
	t_packet packet;
	struct timeval tv;
	ssize_t sended;

	if (gettimeofday(&tv, NULL))
	{
		ft_putendl_fd("Can't gettimeofday", 2);
		exit(EXIT_FAILURE);
	}
	env->count++;
	build_ip_header(env, &packet.ip_header);
	build_icmp_header(env, &packet.icmp_header);
	ft_memcpy(packet.data, &tv, sizeof(tv));
	if ((sended = sendto(env->socket, &packet, sizeof(packet), 0, env->addr, env->addrlen)) == -1)
	{
		ft_putendl_fd("ft_ping: can't send packet", 2);
		exit(EXIT_FAILURE);
	}
	env->sended = epoch_micro();
}
