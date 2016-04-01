/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:11:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/01 21:09:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PING_H
# define FT_PING_H

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <netdb.h>
# include <stdint.h>
# include <unistd.h>
# include <linux/icmp.h>

typedef struct s_env t_env;
typedef struct s_packet t_packet;

struct s_env
{
	char v;
	char *destination;
	char *ip;
	int socket;
	struct sockaddr *addr;
	size_t addrlen;
};

struct s_packet
{
	uint8_t type;
	uint8_t code;
	uint16_t chcksum;
	uint16_t id;
	uint16_t sequence;
	char data[32];
};

void env_init(t_env *env);
void parse_params(t_env *env, int ac, char **av);
void print_help(int fd);
void resolve_destination(t_env *env);
void do_connect(t_env *env);
uint16_t ip_checksum(void *val, size_t len);
void ping_send(t_env *env);

#endif
