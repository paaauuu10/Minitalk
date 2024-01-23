# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbotargu <pbotargu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 17:18:32 by pbotargu          #+#    #+#              #
#    Updated: 2024/01/23 17:18:40 by pbotargu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SOURCES_SERVER = server.c
SOURCES_CLIENT = client.c
SOURCES_SERVER_BONUS = server_bonus.c
SOURCES_CLIENT_BONUS = client_bonus.c

OBJECTS_SERVER = $(SOURCES_SERVER:.c=.o)
OBJECTS_CLIENT = $(SOURCES_CLIENT:.c=.o)
OBJECTS_SERVER_BONUS = $(SOURCES_SERVER_BONUS:.c=.o)
OBJECTS_CLIENT_BONUS = $(SOURCES_CLIENT_BONUS:.c=.o)

all: $(SERVER) $(CLIENT)

# Server executable
$(SERVER): $(OBJECTS_SERVER) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_SERVER)

# Compile server source files
$(OBJECTS_SERVER): $(SOURCES_SERVER)
	$(CC) $(CFLAGS) -c $< -o $@

# Client executable
$(CLIENT): $(OBJECTS_CLIENT) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_CLIENT)

# Compile client source files
$(OBJECTS_CLIENT): $(SOURCES_CLIENT)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

# Bonus Server executable
$(SERVER_BONUS): $(OBJECTS_SERVER_BONUS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_SERVER_BONUS)

# Bonus Compile server source files
$(OBJECTS_SERVER_BONUS): $(SOURCES_SERVER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

# Bonus Client executable
$(CLIENT_BONUS): $(OBJECTS_CLIENT_BONUS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_CLIENT_BONUS)

# Bonus Compile client source files
$(OBJECTS_CLIENT_BONUS): $(SOURCES_CLIENT_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS_SERVER) $(OBJECTS_CLIENT) $(OBJECTS_SERVER_BONUS) $(OBJECTS_CLIENT_BONUS)

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
