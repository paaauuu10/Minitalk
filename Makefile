# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbotargu <pbotargu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 11:27:36 by pbotargu          #+#    #+#              #
#    Updated: 2024/01/19 12:02:27 by pbotargu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FT_PRINTF_PATH = ./ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

SOURCES_SERVER = server.c
OBJECTS_SERVER = $(SOURCES_SERVER:.c=.o)

SOURCES_CLIENT = client.c
OBJECTS_CLIENT = $(SOURCES_CLIENT:.c=.o)

.PHONY: all clean fclean re

all: $(SERVER) $(CLIENT)

$(FT_PRINTF):
	$(MAKE) -s -C $(FT_PRINTF_PATH)

$(SERVER) : $(OBJECTS_SERVER) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJECTS_SERVER) -o $@ -L$(FT_PRINTF_PATH) -lft

$(CLIENT): $(OBJECTS_CLIENT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJECTS_CLIENT) -o $@ -L$(FT_PRINTF_PATH) -lft

$(OBJECTS_SERVER): $(SOURCES_SERVER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECTS_CLIENT): $(SOURCES_CLIENT)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -s -C $(FT_PRINTF_PATH)
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
	$(MAKE) fclean -s -C $(FT_PRINTF_PATH)
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "Clean del Client i del Servidor"

re: fclean all

