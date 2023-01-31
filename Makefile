# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaher <azaher@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 11:13:51 by azaher            #+#    #+#              #
#    Updated: 2023/01/21 13:21:14 by azaher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = ft_split.c \
	  get_next_line.c \
	  get_next_line_utils.c \
	  mapval.c \
	  mapval_utils.c \
	  mapval_utils_2.c \
	  so_long.c \
	  so_long_utils.c \
	  move_player.c \
	  ft_printf.c \
	  ft_put_ptr.c \
	  ft_putchar.c \
	  ft_puthexa_low.c \
	  ft_puthexa_up.c \
	  ft_putnbr.c \
	  ft_putstr.c \
	  ft_unsigned_putnbr.c \
	  print_params.c \
	  pathval.c 
	  
NAME = so_long

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) -I /usr/local/include $(SRC) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean : 
	$(RM) $(NAME)
	
fclean : clean
	$(RM) $(NAME)

re : fclean all
