# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 16:15:02 by clegoube          #+#    #+#              #
#    Updated: 2016/12/02 19:58:19 by clegoube         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fillit
SRC =	fillit.c ft_readfile.c ft_checkfile.c \
		ft_stock.c ft_solve.c ft_coordo.c
HEADER = libft.h


SRCO	= $(SRC:%.c=%.o)

FLAGS =	-Wall -Werror -Wextra
CC =	@gcc -g3

all: $(NAME)

$(NAME) :
		$(CC) -o $(NAME) $(FLAGS) $(SRC) -include $(HEADER) libft.a

clean :
		@rm -f $(SRCO)

fclean : clean
		@rm -f $(NAME)

re : fclean all

.PHONY: clean

#Pensez a retirer cette commande
run: re
	@echo "COMPILED"
	@./fillit extern_file.txt



# NAME =	fillit
# OBJ =	fillit.o ft_readfile.o
# HEADER = libft.h
#
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
#
# all : $(NAME)
#
# $(NAME) : $(OBJ)
# 	ar rc libft.a $(OBJ) && ranlib libft.a
#
# %.o: %.c
# 	$(CC) -o $(NAME) $(CFLAGS) -c $^ -include $(HEADER)
#
# clean :
# 	@rm -f $(OBJ)
#
# fclean : clean
# 	@rm -f $(NAME)
#
# re : fclean all
#
# .PHONY : clean
#
# #Pensez a retirer cette commande
# run: re
# 	@echo "COMPILED"
# 	@./fillit extern_file.txt
#
#
