# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 06:50:12 by acazuc            #+#    #+#              #
#    Updated: 2016/04/02 14:03:48 by acazuc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ping

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ofast

INCLUDES_PATH = includes/

SRCS_PATH = srcs/

SRCS_NAME = main.c \
			parse_params.c \
			resolve_destination.c \
			print_help.c \
			env_init.c \
			connect.c \
			ip_checksum.c \
			ping_send.c \
			epoch_micro.c \
			ping_receive.c \
			sigalrm_handler.c \
			sigint_handler.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY = -L libft/ -lft

all: odir $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@echo " - Making $(NAME)"
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBRARY)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@make -C libft/ clean
	@echo " - Cleaning objs"
	@rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@echo " - Cleaning executable"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir
