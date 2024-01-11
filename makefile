# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 16:44:39 by rhmimchi          #+#    #+#              #
#    Updated: 2024/01/09 22:24:28 by rhmimchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1 = server.c ft_putnbr_fd.c ft_putchar_fd.c
SRC2 = client.c ft_atoi.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRV = server
CLT = client

all: $(SRV) $(CLT)	

$(SRV):$(OBJ1)
	cc $(CFLAGS) $(OBJ1) -o $(SRV)
	
$(CLT):$(OBJ2)
	cc $(CFLAGS) $(OBJ2) -o $(CLT)

%.o:%.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2)
	
fclean: clean
	rm -f $(SRV) $(CLT)

re: fclean all

.PHONY: all libft clean fclean re