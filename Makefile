# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnathali <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 16:52:15 by mnathali          #+#    #+#              #
#    Updated: 2022/03/02 16:52:24 by mnathali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

NAME2 = client

SERV_SRC = ft_putnbr_fd.c serv_code.c

CLIENT_SRC = client_code.c

SERV_OBJ = $(patsubst %.c, %.o, $(SERV_SRC))

CLIENT_OBJ = $(patsubst %.c, %.o, $(CLIENT_SRC))

HEADER = minitalk.h

CC = cc

FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAME2)

$(SERV_OBJ): $(HEADER)

$(CLIENT_OBJ): $(HEADER)

%.o: %.c
	$(CC) $(FLAGS) -c $<

$(NAME): $(SERV_OBJ)
	$(CC) $(FLAGS) $(SERV_OBJ) -o $@

$(NAME2): $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) -o $@

clean:
	rm -rf $(SERV_OBJ) $(CLIENT_OBJ)

fclean: clean
	rm -rf $(NAME) $(NAME2)

bonus: $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re bonus
