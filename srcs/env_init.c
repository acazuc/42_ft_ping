/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:18:28 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/02 16:27:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void env_init(t_env *env)
{
	env->v = 0;
	env->destination = NULL;
	env->count = 0;
	env->received = 0;
	env->times = NULL;
	env->has_received = 0;
}
