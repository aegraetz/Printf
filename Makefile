# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraetz <agraetz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 09:30:21 by anniegraetz       #+#    #+#              #
#    Updated: 2022/03/31 12:10:15 by agraetz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc 
CFLAGS = -Wall -Wextra -Werror -Iheaders -I . -c
RM = rm -f

NAME = libftprintf.a
SRC = ft_printf.c\
	char_check_functions.c\
	ifint.c\

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all 

.PHONY:
	all clean fclean re