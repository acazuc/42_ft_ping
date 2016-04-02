/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 14:03:56 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/02 16:50:12 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_env *g_env;

void	sigint_handler(int sig)
{
	t_time *time;
	size_t min;
	size_t max;
	size_t avg;
	size_t total;
	size_t number;
	size_t deviation;

	g_env->stopped = 1;;
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

	number = 0;
	min = ULONG_MAX;
	max = 0;
	total = 0;
	time = g_env->times;
	while (time)
	{
		if (time->time < min)
			min = time->time;
		if (time->time > max)
			max = time->time;
		total += time->time;
		number++;
		time = time->next;
	}
	if (min == ULONG_MAX)
		min = 0;
	avg = total / number;
	deviation = 0;
	time = g_env->times;
	while (time)
	{
		if (avg < time->time)
			deviation += pow(time->time - avg, 2);
		else
			deviation += pow(avg - time->time, 2);
		time = time->next;
	}
	if (number == 0)
		deviation = 0;
	else
		deviation = sqrt((double)deviation / (double)number);
	printf("rtt min/avg/max/mdev = %.3f/%.3f/%.3f/%.3f ms\n", min / 1000., number == 0 ? 0 : (avg / 1000.), max / 1000., deviation / 1000.);
	exit(EXIT_SUCCESS);
	(void)sig;
}
