/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:21:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/01 21:10:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static void invalid_option(char option)
{
	ft_putstr_fd("ft_ping: invalid option -- '", 2);
	ft_putchar_fd(option, 2);
	ft_putstr_fd("'\n", 2);
	print_help(2);
}

static void parse_option(t_env *env, char *str)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'h')
			print_help(1);
		else if (str[i] == 'v')
			env->v = 1;
		else
			invalid_option(str[i]);
		i++;
	}
}

static int parse_options(t_env *env, int ac, char **av)
{
	int count;

	count = 1;
	while (count < ac)
	{
		if (av[count][0] != '-')
			return (count);
		parse_option(env, av[count]);
		count++;
	}
	return (count);
}

void parse_params(t_env *env, int ac, char **av)
{
	int count;

	count = parse_options(env, ac, av);
	if (count == ac)
		print_help(2);
	env->destination = ft_strdup(av[count]);
}
