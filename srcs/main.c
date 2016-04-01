/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:12:26 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/01 21:09:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int main(int ac, char **av)
{
	t_env env;
	int uid;

	uid = getuid();
	if (uid != 0)
	{
		ft_putendl_fd("You're not root, please use sudo or log as root", 2);
		exit(EXIT_FAILURE);
	}
	env_init(&env);
	parse_params(&env, ac, av);
	resolve_destination(&env);
	do_connect(&env);
	ft_putendl(env.destination);
	ft_putendl(env.ip);
	ping_send(&env);
	return (0);
}
