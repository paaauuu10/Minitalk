# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 11:27:36 by pbotargu          #+#    #+#              #
#    Updated: 2024/01/23 16:33:36 by pbotargu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SOURCES_SERVER = server.c
OBJECTS_SERVER = $(SOURCES_SERVER:.c=.o)

SOURCES_CLIENT = client.c
OBJECTS_CLIENT = $(SOURCES_CLIENT:.c=.o)

.PHONY: all clean fclean re bonus

all: $(SERVER) $(CLIENT)

# Server executable
$(SERVER): $(OBJECTS_SERVER) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_SERVER)

# Client executable
$(CLIENT): $(OBJECTS_CLIENT) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJECTS_CLIENT)

# Compile server source files
$(OBJECTS_SERVER): $(SOURCES_SERVER)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile client source files
$(OBJECTS_CLIENT): $(SOURCES_CLIENT)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS_SERVER) $(OBJECTS_CLIENT)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all
