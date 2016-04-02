/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:03:56 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/02 14:52:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_env *g_env;

void	sigint_handler(int sig)
{
	g_env->stopped = 1;
	ft_putstr("\n--- ");
	ft_putstr(g_env->destination);
	ft_putendl(" ping statistics ---");
	ft_putnbr(g_env->count);
	ft_putstr(" packets transmitted, ");
	ft_putnbr(g_env->received);
	ft_putstr(" received, ");
	if (g_env->count == 0)
		ft_putnbr(0);
	else
		ft_putnbr((1. - ((float)g_env->received / (float)g_env->count)) * 100);
	ft_putstr("% packet loss, time ");
	ft_putnbr(g_env->total_send / 1000);
	ft_putendl("ms");
	printf("rtt min/avg/max/mdev = %.3f/%.3f/%.3f/%.3f ms\n", 0.0, 0.0, 0.0, 0.0);
	exit(EXIT_SUCCESS);
	(void)sig;
}
