/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:52:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/07 21:54:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void print_help(int fd)
{
	ft_putstr_fd("ft_ping: send ICMP ECHO to destination\nUsage: ft_ping [-hv] destination\n-h: show help (this page)\n-v: verbose if packets aren't answered\n", fd);
	if (fd == 2)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
