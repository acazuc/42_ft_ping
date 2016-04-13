/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:11:40 by acazuc            #+#    #+#             */
/*   Updated: 2016/04/02 16:26:29 by acazuc           ###   ########.fr       */
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
# include <limits.h>
# include <math.h>
# include <unistd.h>
# include <linux/icmp.h>
# include <linux/ip.h>
# include <sys/time.h>
# include <signal.h>
# include <stdio.h>

typedef struct s_env t_env;
typedef struct s_packet t_packet;
typedef struct s_time t_time;
typedef struct s_sended t_sended;

struct s_time
{
	size_t time;
	t_time *next;
};

struct s_env
{
	char v;
	char *destination;
	char *ip;
	int socket;
	struct sockaddr *addr;
	size_t addrlen;
	size_t sended;
	uint16_t count;
	uint16_t received;
	int stopped;
	size_t last_send;
	size_t total_send;
	t_time *times;
	int has_received;
};

struct s_packet
{
	struct iphdr ip_header;
	struct icmphdr icmp_header;
	char data[56];
};

void env_init(t_env *env);
void parse_params(t_env *env, int ac, char **av);
void print_help(int fd);
void resolve_destination(t_env *env);
void do_connect(t_env *env);
uint16_t ip_checksum(void *val, size_t len);
void ping_send(t_env *env);
void ping_receive(t_env *env);
size_t epoch_micro(void);
void sigalrm_handler(int sig);
void sigint_handler(int sig);
void time_add(t_env *env, size_t time);

#endif
