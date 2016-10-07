/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 15:56:14 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/02 16:29:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void time_add(t_env *env, size_t time)
{
	t_time *st;

	if (!(st = malloc(sizeof(*st))))
	{
		ft_putendl_fd("ft_ping: can't malloc time struct", 2);
		exit(EXIT_FAILURE);
	}
	st->time = time;
	st->next = env->times;
	env->times = st;
}
