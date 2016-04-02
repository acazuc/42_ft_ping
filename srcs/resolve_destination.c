/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_destination.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:41:32 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/02 13:38:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void resolve_destination(t_env *env)
{
	struct addrinfo *res;
	struct addrinfo hints;
	char tmp[16];

	ft_bzero(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_RAW;
	hints.ai_protocol = IPPROTO_ICMP;
	if (getaddrinfo(env->destination, NULL, &hints, &res))
	{
		ft_putstr_fd("ft_ping: unknown host ", 2);
		ft_putendl_fd(env->destination, 2);
		exit(EXIT_FAILURE);
	}
	if (!res)
	{
		ft_putstr_fd("ft_ping: unknown host: ", 2);
		ft_putendl_fd(env->destination, 2);
		exit(EXIT_FAILURE);
	}
	if (!inet_ntop(AF_INET, &((struct sockaddr_in*)res->ai_addr)->sin_addr, tmp, 16))
	{
		ft_putstr_fd("ft_ping: unknown host ", 2);
		ft_putendl_fd(env->destination, 2);
		exit(EXIT_FAILURE);
	}
	env->ip = ft_strdup(tmp);
	env->addrlen = res->ai_addrlen;
	if (!(env->addr = malloc(res->ai_addrlen)))
	{
		ft_putstr_fd("ft_ping: can't malloc addr\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_memcpy(env->addr, res->ai_addr, res->ai_addrlen);
}
