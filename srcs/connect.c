/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:29:02 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/01 21:09:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void do_connect(t_env *env)
{
	int val;

	if ((env->socket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1)
	{
		ft_putendl_fd("Can't create socket", 2);
		exit(EXIT_FAILURE);
	}
	val = 0;
	if (setsockopt(env->socket, IPPROTO_IP, IP_HDRINCL, &val, sizeof(val)) == -1)
	{
		ft_putendl_fd("Can't setsocketop(IP_HDRINCL)", 2);
		exit(EXIT_FAILURE);
	}
	val = 64;
	if (setsockopt(env->socket, IPPROTO_IP, IP_TTL, &val, sizeof(val)) == -1)
	{
		ft_putendl_fd("Can't setsockopt(IP_TTL)", 2);
		exit(EXIT_FAILURE);
	}
}
