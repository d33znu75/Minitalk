# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 16:44:39 by rhmimchi          #+#    #+#              #
#    Updated: 2024/01/13 23:21:19 by rhmimchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1 = server.c ./src/ft_putnbr_fd.c ./src/ft_putchar_fd.c
SRC2 = client.c ./src/ft_atoi.c

SRC1_BONUS = server_bonus.c ./src/ft_putnbr_fd.c ./src/ft_putchar_fd.c
SRC2_BONUS = client_bonus.c ./src/ft_atoi.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

OBJ1_BONUS = $(SRC1_BONUS:.c=.o)
OBJ2_BONUS = $(SRC2_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRV = server
CLT = client

SRV_BONUS = server_bonus
CLT_BONUS = client_bonus

all: $(SRV) $(CLT)	

$(SRV):$(OBJ1)
	cc $(CFLAGS) $(OBJ1) -o $(SRV)
	
$(CLT):$(OBJ2)
	cc $(CFLAGS) $(OBJ2) -o $(CLT)

bonus: $(SRV_BONUS) $(CLT_BONUS)

$(SRV_BONUS):$(OBJ1_BONUS)
	cc $(CFLAGS) $(OBJ1_BONUS) -o $(SRV_BONUS)
	
$(CLT_BONUS):$(OBJ2_BONUS)
	cc $(CFLAGS) $(OBJ2_BONUS) -o $(CLT_BONUS)

%.o:%.c ./src/minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ1) $(OBJ2) $(OBJ1_BONUS) $(OBJ2_BONUS)
	
fclean: clean
	rm -f $(SRV) $(CLT) $(SRV_BONUS) $(CLT_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus