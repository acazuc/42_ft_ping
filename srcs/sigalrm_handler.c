/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigalrm_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:01:11 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/02 15:44:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_env *g_env;

void sigalrm_handler(int sig)
{
	t_packet packet;
	g_env->total_send += epoch_micro() - g_env->last_send;
	g_env->last_send = epoch_micro();
	alarm(1);
	packet = ping_send(g_env);
	ping_receive(g_env, packet);
	(void)sig;
}
