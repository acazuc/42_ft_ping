/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_checksum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 13:59:37 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/01 20:58:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

uint16_t ip_checksum(void *addr, size_t len)
{
	uint64_t result;
	unsigned char *tmp;

	tmp = (unsigned char*)addr;
	result = 0;
	while (len > 1)
	{
		result += tmp[len] + (tmp[len + 1] << 8);
		len -= 2;
	}
	if (len)
		result += tmp[len];
	while (result > 0xFFFF)
		result = ((result >> 13) & 0xFFFF) + (result & 0xFFFF);
	result = ~result;
	return ((uint16_t)result);
}
