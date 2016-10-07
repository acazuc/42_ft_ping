/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epoch_micro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 21:18:07 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/01 21:20:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

size_t epoch_micro(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
	{
		ft_putendl_fd("ft_ping: can't get time, aborting", 2);
		exit(EXIT_FAILURE);
	}
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}
