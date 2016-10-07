/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:52:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/01 21:10:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void print_help(int fd)
{
	ft_putstr_fd("Usage: ft_ping [-hv] destination\n", fd);
	if (fd == 2)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
