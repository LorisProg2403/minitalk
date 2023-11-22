# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaume <lgaume@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 12:54:10 by lgaume            #+#    #+#              #
#    Updated: 2023/11/22 13:44:45 by lgaume           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
LIBFT 	=	./libft/libft.a
RM		=	rm -rf

# MINITALK FILES
SERVER	=	server
CLIENT	=	client

SERVER_SRC	=	src/server.c
CLIENT_SRC	=	src/client.c 

SERVER_OBJ	=	$(SERVER_SRC:.c=.o)
CLIENT_OBJ	=	$(CLIENT_SRC:.c=.o)

# Rules
all :			$(SERVER) $(CLIENT)

$(LIBFT) :	
				@make -C ./libf	

$(SERVER) :		$(SERVER_OBJ) $(LIBFT)
				$(CC) $(FLAGS) $(SERVER_OBJ) $(LIBFT) -o $(SERVER)

$(CLIENT) :		$(CLIENT_OBJ) $(LIBFT)
				$(CC) $(FLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT)

clean :			
				@make clean -C ./libft
				$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)

fclean :		clean
				@make fclean -C ./libft
				$(RM) $(SERVER) $(CLIENT)

re :			fclean all

.PHONY :		all re clean fclean
			