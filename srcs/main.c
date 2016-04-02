/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:12:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/02 16:12:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_env *g_env;

int main(int ac, char **av)
{
	t_env env;

	g_env = &env;
	if (getuid() != 0)
	{
		ft_putendl_fd("You're not root, please use sudo or log as root", 2);
		exit(EXIT_FAILURE);
	}
	env_init(&env);
	parse_params(&env, ac, av);
	resolve_destination(&env);
	do_connect(&env);
	env.total_send = 0;
	ft_putstr("PING ");
	ft_putstr(env.destination);
	ft_putstr(" (");
	ft_putstr(env.ip);
	ft_putstr(") ");
	ft_putnbr(sizeof(t_packet) - sizeof(t_ip_header) - sizeof(t_icmp_header));
	ft_putchar('(');
	ft_putnbr(sizeof(t_packet));
	ft_putendl(") bytes of data.");
	signal(SIGINT, &sigint_handler);
	signal(SIGALRM, &sigalrm_handler);
	env.last_send = epoch_micro();
	alarm(1);
	while (!env.stopped)
	{
		ping_receive(&env);
	}
	return (0);
}
