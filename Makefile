# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 20:35:28 by idabligi          #+#    #+#              #
#    Updated: 2022/11/19 18:02:11 by idabligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

FLS = ft_printf printf_hex printf_ptr printf_uns ft_printf_utils\

FO = $(FLS:=.o)

all : $(NAME)

$(NAME) : $(FO)
	$(AR) $(NAME) $(FO)

%.o : %.c ft_printf.h
	$(CC) -c $(FLAGS) $<

clean :
	$(RM) $(FO)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
