# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 11:27:36 by pbotargu          #+#    #+#              #
#    Updated: 2024/01/22 12:22:31 by pbotargu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRCS_SERVER = server.c
OBJ_SERVER = $(SRCS_SERVER:.c=.o)

SRCS_CLIENT = client.c
OBJ_CLIENT = $(SRCS_CLIENT:.c=.o)

.PHONY: all clean fclean re bonus

all: $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -s -C $(LIBFT_PATH)

$(SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $@ -L$(LIBFT_PATH) -lft

$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $@ -L$(LIBFT_PATH) -lft

$(OBJ_SERVER): $(SRCS_SERVER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_CLIENT): $(SRCS_CLIENT)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -s -C $(LIBFT_PATH)
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	$(MAKE) fclean -s -C $(LIBFT_PATH)
	$(RM) $(SERVER) $(CLIENT) 
	@echo "Clean del Client i del Servidor"

re: fclean all
